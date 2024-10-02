#include<Servo.h>
Servo s1;
void setup()
{
  //Serial.begin(9600);
  s1.attach(9);
  pinMode(A0,INPUT);
}
void loop()
{
  int a = analogRead(A0);
  int b= map(a,0,1023,0,180);
  s1.write(b);
}
