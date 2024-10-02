int button = 7;
int led = 12;

void setup()
{
  //Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}
void loop()
{
  int a = digitalRead(button);
  if(a==HIGH)
  digitalWrite(led,LOW);
  else
  digitalWrite(led,HIGH);
  //Serial.println(brightness);
}
