delete(instrfind({'Port'},{'COM7'}));

arduino = serial('COM7');
arduino.BaudRate = 9600;
warning('off', 'MATLAB:serial:fscanf:unsuccessfulRead');
fopen(arduino);
fgets(arduino);

ts = 1; % periodo de amostragem
tempo = input('Digite por quantos segundos serao obtidas amostras: ');
total_amostras = tempo / ts;
tplot = (0:1:tempo);

for i = 1:total_amostras

setpoint(i)=fscanf(arduino,'%d');
fprintf('Setpoint = %d\t', setpoint(i));
subplot(2,2,1)
plot(setpoint, 'r');
j=i+1;

sensor(j)=fscanf(arduino,'%d');
fprintf('Sensor PWM = %d\t', sensor(j));
subplot(2,2,2)
plot(sensor, 'g');
k=j+1;

erro(k)=fscanf(arduino,'%f');
fprintf('erro = %-3.2f\t ', erro(k));
subplot(2,2,3)
plot(erro, 'y');
l=k+1;

amostras(l)=fscanf(arduino,'%d');
fprintf('nivel = %d\n',amostras(l));
subplot(2,2,4)
plot(amostras)
drawnow

end

figure(5)
plot(setpoint, 'r')
legend('PI - Nível/Vazão')
xlabel('Amostras')
ylabel('Variaveis do Sistema')

hold on;
plot(sensor, 'g')
hold off;

hold on;
plot(erro, 'y')
hold off;

hold on;
plot(amostras,'b')
hold off;

fclose(arduino);
disp('Fim da amostragem.');
disp('Pressione qualquer tecla para encerrar o programa.');
pause(0.1);
delete(arduino);
clear all;