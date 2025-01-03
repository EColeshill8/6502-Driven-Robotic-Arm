#define PI 3.1415926535897932384626433832795
#include <Servo.h>

/*
JOYSTICK
VRX pin A1
VRY pin A0
SWITCH pin 7

180 degree SERVOS
SERVO 1 signal pin 5
SERVO 2 signal pin 6
*SERVO 2 is attached to SERVO 1 which attaches to workbench
*/

Servo myservo1; // Initilizing servos
Servo myservo2;

// Intitilizing variables
float a = 0.0; // "a" is x coordinate of desired possition for arm end
float b = 1.5; // "b" is y coordinate of desired possition for arm end
float Ay0 = 0.0; 
float Ax1 = 0.0;
float adjx = 0;
float adjy = 0;
int angle1 = 90;
int angle2 = 90;
int SWITCH = 0;
float A11 = 0; // Two solutions for any given (a,b) point and two servos, so divided into solution/servo. So 11 would be angle solution one, servo one and so on
float A12 = 0;
float A21 = 0;
float A22 = 0;
int lastServo1Angle = 90; // Initialize to default angle
int lastServo2Angle = 90;

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(5, 500, 2500); // Initilizing servos
  myservo1.write(90);
  myservo2.attach(6, 500, 2500);
  myservo2.write(90);
  Serial.begin(9600); // Initilize serial monitor
  pinMode(7, INPUT); // Sets switch on joystick to pin 7. Currently not used
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Ay0 = analogRead(A0); // Joystick y input
  Ax1 = analogRead(A1); // Joystick x input
  SWITCH = digitalRead(7); // Switch on joystick input. Currently not used

  // Solution 1 and 2 for circle intersections (where limb one and limb two will meet when end point is on point (a,b))
  float X1 = ((b * (-1 * b * ((-1 * (pow(a, 3))/sq(b)) -1 * a) + (sqrt(-1 * (pow(a, 4)) -2 * (sq(a) * sq(b)) + 4 * (sq(a)) - (pow(b, 4)) + 4 * (sq(b)))))) / (2 * ((sq(a)) + (sq(b)))));
  float Y1 = (((-2 * a * X1) + (sq(a)) + (sq(b))) / (2 * b));
  float X2 = ((b * (-1 * b * ((-1 * (pow(a, 3))/sq(b)) -1 * a) - (sqrt(-1 * (pow(a, 4)) -2 * (sq(a) * sq(b)) + 4 * (sq(a)) - (pow(b, 4)) + 4 * (sq(b)))))) / (2 * ((sq(a)) + (sq(b)))));
  float Y2 = (((-2 * a * X2) + (sq(a)) + (sq(b))) / (2 * b));

// Adjx/y is map of controller axis as a percentage. When controller axis is changed past impatience value, system updates point (a,b)
  adjx = (((Ax1 - 511.5) / 1023) * 1); // * 1 can be used to change scaling of servo map
  adjy = ((((Ay0 - 511.5) / 1023)) * 1);
  if (adjx > 0.2 && a > -2) {
    a -= 0.1;
  }
  if (adjx < -0.2 && a < 2) {
    a += 0.1;
  }
  if (adjy < 0.2 && b > -2) {
    b -= 0.1;
  }
  if (adjy > -0.2 && b < 2) {
    b += 0.1;
  }

// Solving for servo angles in rad (AR = Angle in radians following solution and servo naming rule). Simplified dot product used
  float AR11 = acos(-1 * X1); 
  float AR21 = acos(-1 * X2);
  float AR12 = acos((-1 * X1) + (b * X1) - (a * Y1) - (b * Y1) + sq(X1) + sq(Y1));
  float AR22 = acos((-1 * X2) + (b * X2) - (a * Y2) - (b * Y2) + sq(X2) + sq(Y2));
  
// Converting AR (Angle in radians) to AD (Angle in degrees)
  float AD11 = AR11 * (180 / PI);
  float AD21 = AR21 * (180 / PI);
  float AD12 = AR12 * (180 / PI);
  float AD22 = AR22 * (180 / PI);
  
// Adding acceleration factor to angle request and incrementing angle 
  A11 += 0.4 * (AD11 - A11);
  A12 += 0.4 * (AD12 - A12);
  A21 += 0.4 * (AD21 - A21);
  A22 += 0.4 * (AD22 - A22);

// Tests new servo angle
  int newServo1Angle = round(A11);
  int newServo2Angle = round(A12);
 
 // Updates the servo positions only if the angle has changed significantly
  if (abs(newServo1Angle - lastServo1Angle) > 1) {
    myservo1.write(newServo1Angle);
    lastServo1Angle = newServo1Angle;
  }

  if (abs(newServo2Angle - lastServo2Angle) > 1) {
    myservo2.write(newServo2Angle);
    lastServo2Angle = newServo2Angle;
  }

  Serial.print(Ay0); //stack of serial prints for debugging
  Serial.print("     ");
  Serial.print(Ax1);
  Serial.print("     ");
  Serial.print(a);
  Serial.print("     ");
  Serial.print(b);
  Serial.print("     ");
  Serial.print(X1);
  Serial.print("     ");
  Serial.print(Y1);
  Serial.print("     ");
  Serial.print(adjx);
  Serial.print("     ");
  Serial.print(X2);
  Serial.print("     ");
  Serial.print(Y1);
  Serial.print("     ");
  Serial.print(A11);
  Serial.print("     ");
  Serial.print(A12);
  Serial.println();
  delay(100);
}

