#include <Servo.h>

int analogIn = A0;
int digitalIn = D1;
int ledOne = D2;
int servoStop = 96;

Servo waterCanon;

void setup ()
{
  pinMode (analogIn, INPUT);
  pinMode (digitalIn, INPUT);
  pinMode (ledOne, OUTPUT);
  waterCanon.attach(D3);
  Serial.begin (9600);
}
  

void loop ()
{
  float  analogValue;
  int digitalValue;

  int i = 0;
  bool t = false;
  digitalWrite (ledOne, LOW);
  waterCanon.write(servoStop);
  while (i < 100)
  {
    digitalValue = digitalRead (digitalIn);
    if  (digitalValue==1) 
    {
      Serial.println ("We are live");
      t = true;
      break;
    }
    i++;
  }
  
  if (t) 
  {
      Serial.println ("Set of water 'canon'");
      digitalWrite (ledOne, HIGH);

      // Full speed ahead for 0,5 seconds
      waterCanon.write(0);
      delay(500);
      // Hoooold..!
      waterCanon.write(servoStop);
      delay(2000);
      // Backup
      waterCanon.write(180);
      delay(500);
  }
}
