//pins
//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2048;//or 512 steps per rotation

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 10, 11, 12, 13);
// Motor A (drive motor) connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B (up and down motor) connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  //state machine using functions
  if(!pressed()){
  IDLE();
  }else{
  startFarming();
  Drive();
  Drilling();
  Seeding();
  Watering();
  Filling();
  }
}
//functions
bool pressed(){

  return true;
}

void IDLE(){
  //default settings
}

void startFarming(){
  delay(2000);
}

void Drive(){
  //motor A runs for 2 secs
  /*
  unsigned long timeBegin = millis();
  int duration = 0;
  while(duration<=2000){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   unsigned long timeEnd = millis();
   duration = timeEnd - timeBegin;
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  */
  void Drive(){
  static unsigned long timeBegin = 0;
  static bool motorRunning = false;

  if (!motorRunning) {
    // Start motor and record time
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    timeBegin = millis();
    motorRunning = true;
  }

  // Check if 2 seconds have passed
  if (motorRunning && millis() - timeBegin >= 2000) {
    // Stop motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    motorRunning = false;
  }
}


void Drilling(){
  //stepper rotates to the special position
  // Rotate CW slowly at 5 RPM
  myStepper.setSpeed(5);//speed to be changed later to better fit the system
  myStepper.step(stepsPerRevolution);
  delay(1000);// time to be changed to better fit the system

  //motor B goes down for 3 secs then goes up to intial position
  static unsigned long timeBegin = 0;
  static bool motorRunning = false;

  //motor goes down
  if (!motorRunning) {
    // Start motor and record time
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    timeBegin = millis();
    motorRunning = true;
  }

  // Check if 3 seconds have passed
  if (motorRunning && millis() - timeBegin >= 3000) {
    // Stop motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    motorRunning = false;
  }
  //motor goes up
  if (!motorRunning) {
    // Start motor and record time
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    timeBegin = millis();
    motorRunning = true;
  }

  // Check if 2 seconds have passed
  if (motorRunning && millis() - timeBegin >= 3000) {
    // Stop motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    motorRunning = false;
  }
}

void Seeding(){
  //no connected motor in the proof of concept but in theory
  //the stepper motor goes to the the second special position then
  // Rotate CW slowly at 5 RPM
  myStepper.setSpeed(5);//speed to be changed later to better fit the system
  myStepper.step(stepsPerRevolution);
  delay(1000);// time to be changed to better fit the system
  //the third DC moto will go down with a tube connected to the seed bowel and some seeds go down
}

void Watering(){
  //in theory
  //the stepper motor goes to the third special position
  // Rotate CW slowly at 5 RPM
  myStepper.setSpeed(5);//speed to be changed later to better fit the system
  myStepper.step(stepsPerRevolution);
  delay(1000);// time to be changed to better fit the system
  //the water pump pumps water in the hole threw a tube
}

void Filling(){
  //the robot goes forward forr 2 secs to make the back piece fill the hole
  static unsigned long timeBegin = 0;
  static bool motorRunning = false;

  if (!motorRunning) {
    // Start motor and record time
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    timeBegin = millis();
    motorRunning = true;
  }

  // Check if 2 seconds have passed
  if (motorRunning && millis() - timeBegin >= 2000) {
    // Stop motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    motorRunning = false;
  }
}
