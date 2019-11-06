#include <Servo.h>

#include "FctET2Nano.h"

#define pot A0
#define S1 A1
#define D1 4
#define D2 3
#define D3 2
#define ServoPin 9

Servo servo;

enum Mode {MANUAL, NEUTRAL, AUTO};

const byte SERVO_STOP = 90;

Mode eMode;
byte bMode = 1;
int iPot;
byte bS1 = INACTIF;
byte bServoPos;

bool boL1 = false;
bool boL2 = false;
bool boL3 = false;

bool boServoUp = false;

void setup() {
  pinMode(S1, INPUT_PULLUP);
  servo.attach(ServoPin);

  digitalWrite(D1, boL1);
  digitalWrite(D2, boL2);
  digitalWrite(D3, boL3);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

}

void loop() {
  UserInput();
  TreatementSwitch();
  TreatementPot();
  TreatementMode();
  ServoMotor();
  Leds();
}
