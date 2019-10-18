// PI digital

const int digitalSET = 12; // entrada digital SETPOINT nível
const int analogSEN = A1; // entrada analogica SENSOR PWM
const int analogOutPin = 9; // Analog output pin gate mosfet
const int limiarI = 500;
const int Ta = 100;

int distancia;
int centimetro;
int i=0;
int n=0;
int media=0;
int soma=0;
int sensorValue = 0;
int outputValue = 0; //variavel que carrega o valor enviado para a 
//saída digital modulada em PWM, variacao de 0 a 255
float SetPoint; //variavel setpoint referente ao nível lido pelo ultrasônico
float erro = 0;
float controle=0;
float Kp = 1;
float Ki = 1;
float errop = 0;
float controlep = 0;
float contP;
float contI;

void setup() {
// inicializa comunicação serial em 9600 bps:
Serial.begin(9600);
pinMode(digitalSET, INPUT);
pinMode(13, OUTPUT);
pinMode(analogOutPin, OUTPUT);
}

void loop() {
//leitura nível sensor ultrasônico
digitalWrite(13, HIGH);
delayMicroseconds(10);
digitalWrite(13, LOW);
distancia = pulseIn(digitalSET, HIGH);
centimetro = distancia/58;
centimetro = 32 - centimetro;
soma=soma+centimetro;
n++;

if (n==20)
{
media = soma/n;
n=0;
soma=0;
if (media==24)
{
  i++;
}
else
{
i=0;
}
if (i>=3)
{
media=25;
}
//-------------------------
//calculo conversão setpoint
//-------------------------
SetPoint = media*102.4;
SetPoint = 2560 - SetPoint;
}
//-------------------------
// leituta do sensor PWM:
//-------------------------
//valor atual
sensorValue = analogRead(analogSEN);
//-------------------------
errop = erro; //valor anterior do erro
//calculo do erro
erro = SetPoint - sensorValue;
//CONTROLADOR
controlep = contI;
//etapa proporcional
contP = Kp*erro;
//etapa integral
if (abs(erro) < limiarI)
contI = Ki*(controlep + Ta*0.001*erro); //transformando ms para s
else
contI = 0;
//saida do controlador
controle = contP + contI;
//SAIDA
//------------------------
// saturacao e escalamento da variavel de saida
controle = constrain(controle,-1023, 1023);
outputValue = map(controle, -1023, 1023, 0, 255);
//Valor de saída PWM
analogWrite(analogOutPin, outputValue);
Serial.println(SetPoint);
Serial.println(sensorValue);
Serial.println(erro);
Serial.println(media);
delay(Ta);
}


