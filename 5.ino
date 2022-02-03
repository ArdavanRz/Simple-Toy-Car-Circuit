#include <Servo.h>

int servoPin1 = 21;
int servoPin2 = 20;
int frontlight1 = 18;
int frontlight2 = 17;
int buzzer = 19;
int wheel1 = 8 ;
int wheel2 = 9 ;
Servo steer1;
Servo steer2;
int input=0;
void setup() {
  pinMode(frontlight1, OUTPUT);
  pinMode(frontlight2, OUTPUT);
  
  pinMode(wheel1, OUTPUT);
  pinMode(wheel2, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
  steer1.attach(servoPin1);
  steer2.attach(servoPin2);
}

void loop() {

  if (Serial.available() > 0){
    input=Serial.parseInt();
    Serial.println(input);
  }
   
  
  if (input == 179){
   digitalWrite(frontlight2, HIGH);
   digitalWrite(frontlight1, HIGH);
   Serial.print("\n");
   Serial.print("Front Lights ON!");
   Serial.print("\n");
   input = 1000;
   
   }

  if (input == 279){
   digitalWrite(frontlight2, LOW);
   digitalWrite(frontlight1, LOW);
   Serial.print("\n");
   Serial.print("Front Lights OFF");
   Serial.print("\n");
   input = 1000;
   }

  if (input > 0 && input <= 180){
    steer1.write(input);
    steer2.write(input);
    Serial.print("\n");
    Serial.print("Front wheels set to :");
    Serial.print(input);
    Serial.print("\n");
    input = 1000;
  }

  if (input == 555) {
    tone(buzzer, 1000);
    Serial.print("\n");
    Serial.print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    delay(500);
    noTone(buzzer);
    input = 1000;
  }

   if (input == 213) {
    digitalWrite(wheel1, HIGH);
    digitalWrite(wheel2, HIGH);
  }

  if (input == 313) {
    digitalWrite(wheel1, LOW);
    digitalWrite(wheel2, LOW);
  }

  
}
  
