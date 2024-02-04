#include <Servo.h>


#define MODE 0 
// MODE ---> 0 for comand line with GUI mode in python
//MODE ----> 1 for joystick mode control
#define BASE_ANGLE 0
#define SHOULDER_ANGLE 70
#define ELBOW_ANGLE 90
#define WRIST_ANGLE 45
#define GRIPPER_ANGLE 0


Servo baseservo;  // create servo object to control a servo
Servo shoulderservo;
Servo elbowservo;
Servo gripperservo;
Servo wristservo;

// Define the pins for the joystick and motor
const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickKPin = A2;
int sensor_pin = A3; 

// Define the minimum and maximum values for the joystick
const int joystickMin = 0;
const int joystickMax = 1023;

// Define the minimum and maximum angles for the joystick
const int joystickAngleMin = -90;
const int joystickAngleMax = 90;

bool crabAnimation = false;
bool helloAnimation = false;
bool specialAnimation = false;

void setDefaultPos(){

  baseservo.write(BASE_ANGLE);
  shoulderservo.write(SHOULDER_ANGLE);
  elbowservo.write(ELBOW_ANGLE);
  wristservo.write(WRIST_ANGLE);
  gripperservo.write(GRIPPER_ANGLE);

}


void setup() {

  //Port for comunication with python
  Serial.begin(115200);


  // Declare servo motors
  baseservo.attach(9);  
  shoulderservo.attach(10);  
  elbowservo.attach(11);
  wristservo.attach(12);
  gripperservo.attach(13);


  //Set default position
  setDefaultPos();
}

void loop() {

  //Read sensor value
  int data = analogRead(sensor_pin);
  Serial.println(data);



   if (Serial.available() > 0) {

    String angle = Serial.readString();

    switch(angle[0]){
      case 'b' :
        baseservo.write((angle.substring(1, angle.length())).toInt());
        break;
      case 's' :
        shoulderservo.write((angle.substring(1, angle.length())).toInt());
        break;
      case 'e' :
        elbowservo.write((angle.substring(1, angle.length())).toInt());
        break;
      case 'w' :
        wristservo.write((angle.substring(1, angle.length())).toInt());
        break;
      case 'g' :
        gripperservo.write((angle.substring(1, angle.length())).toInt());
        break;
      case 'C' :
        if (crabAnimation) crabAnimation = false;
        else crabAnimation = true;
        break;
      case 'H' :
        if (helloAnimation) helloAnimation = false;
        else helloAnimation = true;
        break;
      case 'S' :
        specialAnimation = true;
        break;
    }
    
  }

  if (crabAnimation){
    gripperservo.write(180);
    gripperservo.write(0);
  }

  if (helloAnimation){
    baseservo.write(180);
    delay(1000);
    baseservo.write(0);
  }

  if (specialAnimation){
    shoulderservo.write(40);
    elbowservo.write(0);
    specialAnimation = false;
  }

  //delay(1000);        // small delay to prevent jitter or noise in joystick reading
}


