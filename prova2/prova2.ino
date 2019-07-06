#include <Ultrasonic.h>
#include <Servo.h>
#include <Wire.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define servo 6
Servo s;


//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

float ultimas10[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
  s.attach(servo);
  s.write(0);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  Wire.begin();
  
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float soma = 0;
  float taxaConversao = 1.8;
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  for (int i = 9; i > 0; i--){ultimas10[i] = ultimas10[i-1];}
  ultimas10[0] = cmMsec;
  for (int i = 0; i < 10; i++){soma = soma + ultimas10[i];}
  float media = soma/10;
  //Condiçãod e máximos e mínimos
  //Exibe informacoes no serial monitor
  if(media < 3) media = 0;
  if(media > 100) media = 100;
  float angulo = roundf(media*taxaConversao);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  Serial.println("Média dos valores: ");
  Serial.println(media);
  Serial.println("Ângulo do Servo");
  Serial.println(angulo);
  if (angulo > 170) angulo = 170;
  if (angulo < 10) angulo = 10;
  s.write(180 - angulo);
  Wire.beginTransmission(0x08);
  Wire.write(round(media));
  Wire.endTransmission();
  delay(50);
}
