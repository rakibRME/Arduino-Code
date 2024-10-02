#include <Servo.h>
Servo servo_big;
Servo servo_small;


char t = 'x';


int servo_control = 0;

int servo_small_position = 90;
int servo_big_position = 90;

               
void setup()
{
  Serial.begin(9600);        
  pinMode(9, OUTPUT);    
  pinMode(10, OUTPUT);    
  pinMode(11, OUTPUT);    
  pinMode(12, OUTPUT);

 servo_big.attach(5);
 servo_small.attach(6);

}

void loop()
{
  if(Serial.available() > 0)  
  {
     t = Serial.read();
     Serial.print("t: ");
     Serial.print(t);


     Serial.println("");
  }

  if (servo_control == 0)
  {
  if( (t == 'F')){
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  else if( (t == 'B')){
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }
  else if( (t == 'L')){
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  else if( (t == 'R')){
    digitalWrite(9, HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  else if( (t == 'S'))
  {
    digitalWrite(9, HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
  }
  }

   if ( (t == 'W') && (servo_control == 0)){
    servo_control = 1;
  }
  else if ( (t == 'w') && (servo_control == 1)){
    servo_control = 0;
  }

  if (servo_control == 1)
  {
  if( (t == 'F')){
    servo_small_position = servo_small_position + 1;
    Serial.print("servo_small_position:");
    Serial.print(servo_small_position);
  }
  else if( (t == 'B')){
    servo_small_position = servo_small_position - 1;
    Serial.print("servo_small_position:");
    Serial.print(servo_small_position);
  }
  if( (t == 'R')){
    servo_big_position = servo_big_position - 1;
    Serial.print("servo_big_position:");
    Serial.print(servo_big_position);
  }
  else if( (t == 'L')){
    servo_big_position = servo_big_position + 1;
    Serial.print("servo_big_position:");
    Serial.print(servo_big_position);
  }

  if ( servo_big_position < 0 )
  {
    servo_big_position = 0;
  }
  if ( servo_big_position > 180 )
  {
    servo_big_position = 180;
  }
  if ( servo_small_position < 0 )
  {
    servo_small_position = 0;
  }
  if ( servo_small_position > 180 )
  {
    servo_small_position = 180;
  }

  servo_big.write(servo_big_position);
  servo_small.write(servo_small_position);
  }

}