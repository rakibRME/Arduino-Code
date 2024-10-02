int button = A0;
int led = 9;
void setup()
{
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{
  int a = analogRead(button);
  int brightness= map(a,0,1023,0,255);
  analogWrite(led,brightness);
}
