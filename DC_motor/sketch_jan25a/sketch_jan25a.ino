#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 19 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 18
#define IN2 5

// motor 2 settings
#define IN3 17
#define IN4 16
#define ENB 4// this pin must be PWM enabled pin if Arduino board is used
#define CHB 1

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

// for single motor
//Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA, true);	

// for two motors without debug information	// Watch video instruciton for this line: https://youtu.be/2JTMqURJTwg
Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB);

// fore two motors with debut information
//Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA, IN3, IN4, ENB, CHB, true);

void setup() {
  Serial.begin(115200);
  robot.begin();
  //L298N DC Motor by Robojax.com

}

void loop() {
  
 // robot.demo(1);
  robot.rotate(motor1, 80, CW);//run motor1 at 60% speed in CW direction
  robot.rotate(motor2, 70, CCW);//run motor1 at 60% speed in CW direction
  
  delay(3000);

  robot.brake(1);
  robot.brake(2);  
  delay(2000);


  robot.rotate(motor1, 100, CW);//run motor1 at 60% speed in CW direction
  delay(3000);
  
  robot.rotate(motor2, 100, CCW);//run motor1 at 60% speed in CW direction
  
  robot.brake(1);
  robot.brake(2);   
  delay(2000);  

  for(int i=0; i<=100; i++)
  {
    robot.rotate(motor1, i, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    delay(100);
  }
  delay(2000);
  
  robot.brake(1);
  delay(2000);  
  
  for(int i=0; i<=100; i++)
  {
    robot.rotate(motor2, i, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    delay(100);
  }
  delay(2000);
  
  robot.brake(2);
  delay(2000);    
  // Robojax L298N Library. Watch video instruciton https://youtu.be/2JTMqURJTwg
}