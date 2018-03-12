
#include <Servo.h> //read up here:https://www.arduino.cc/en/Tutorial/Knob

Servo hand;
Servo base;
int armState;
int armSpeed=50;

void setup() {
  Serial.begin(9600);
  hand.attach(10);
  base.attach(9);
  Serial.println("Pins registered.");
  armState=90;
  delay(1000);
  Serial.println("Set initial hand position to Open");
  openHands();
}

void loop() {
  Serial.println("Set initial Arm position to 0");
  moveArm(0);
  Serial.println("Waiting for Parcel...");
  delay(10000);
  Serial.println("Close Hand");
  closeHands();
  delay(1000);
  Serial.println("Turn to 90");
  moveArm(90);
  delay(1000);
  Serial.println("Open Hand");
  openHands();
  delay(1000);
  Serial.println("Turn to 180");
  moveArm(180);
}

void closeHands(){
  hand.write(0);
  delay(1000);
}

void openHands(){
  hand.write(135);
  delay(1000);
}

void moveArm(int pos){
  Serial.print("Moving arm to ");
  Serial.print(pos);
  Serial.print(" from ");
  Serial.println(armState);
  
  if (armState>pos){
    for (;armState>pos; armState--){
      base.write(armState);
//      Serial.println(armState);
      delay(armSpeed);
    }
    Serial.println(armState);
    base.write(armState);
  }else{
    Serial.println(armState);
    base.write(armState);
    for (;armState<pos; armState++){
      base.write(armState);
//      Serial.println(armState);
      delay(armSpeed);
    }
  }
  delay(1000);
}

void gotoDropoff(){
  base.write(90);
  delay(1000);
  
}

