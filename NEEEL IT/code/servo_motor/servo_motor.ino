#include <Servo.h>
#include <math.h>

#define pi 3.1415
#define BASE_ANGLE 0
#define SHOULDER_ANGLE 50
#define ELBOW_ANGLE 45
#define WRIST_ANGLE 150
#define GRIPPER_ANGLE 30

// Joint angles
float theta1 = BASE_ANGLE;
float theta2 = SHOULDER_ANGLE;
float theta3 = ELBOW_ANGLE;
float theta4 = WRIST_ANGLE;

// Servo motors
Servo base;
Servo shoulder;
Servo wrist;
Servo arm;

// Link lengths (in cm)
float L1 = 6.0;
float L2 = 12.0;
float L3 = 10.0;
float L4 = 0.0;

void setup() {
  // Attach servo motors
  base.attach(9);
  shoulder.attach(10);
  wrist.attach(11);
  arm.attach(12);

  // Set initial joint angles
  base.write(90);
  shoulder.write(90);
  wrist.write(90);
  arm.write(90);

  // Wait for servos to reach initial position
  delay(1000);
}

void loop() {
  // Define target position (in cm)
  float x = 10;
  float y = 10;
  float z = 10;

  // Compute HD method
  float r1 = sqrt(x*x + y*y + z*z);
  float phi1 = atan2(y, x);
  float phi2 = atan2(sqrt(x*x + y*y), z);
  float r3 = sqrt(r1*r1 - L4*L4);
  float phi3 = acos((r3*r3 + L2*L2 - L3*L3) / (2*r3*L2));
  float psi3 = atan2(L4, r3);
  float psi2 = acos((L2*L2 + L3*L3 - r3*r3) / (2*L2*L3));
  float psi1 = atan2(z, sqrt(x*x + y*y));
  float a = sqrt((L2*L2) + (L3*L3) - (2*L2*L3*cos(psi2)));
  float b = sqrt((r1*r1) - (L4*L4));
  float gamma = atan2(L4, b);
  float delta = acos((a*a) + (b*b) - (L2*L2) - (L3*L3)) / (2*a*b);
  theta1 = phi1;
  theta2 = pi/2 - phi2;
  theta3 = pi/2 - (phi3 + psi3);
  theta4 = pi/2 - psi2 - delta - gamma;

  // Convert joint angles to servo positions
  int base_pos = (int)(theta1 * 180 / pi);
  int shoulder_pos = (int)(theta2 * 180 / pi);
  int wrist_pos = (int)(theta3 * 180 / pi);
  int arm_pos = (int)(theta4 * 180 / pi);

  // Move servo motors to new positions
  base.write(base_pos);
  shoulder.write(shoulder_pos);
  wrist.write(wrist_pos);
  arm.write(arm_pos);

  // Delay for smoother motion
  delay(10);
}