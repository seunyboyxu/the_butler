//Define Motor Pins
#define IN1 13
#define IN2 12
#define IN3 11
#define IN4 10

#include <Servo.h>



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SetupPins();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void SetupPins()
{
  //Assign Motors to Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);



}

void Forward(int duration) //one chair?
{
  // Run left motor forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);;

  //Run right motor forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(duration);
  //900
  //356

  Stop();

}

void Backward(int duration) //one chair?
{
  // Run left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);;

  //Run right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(duration);
  //900
  //356

  Stop();

}


void Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}