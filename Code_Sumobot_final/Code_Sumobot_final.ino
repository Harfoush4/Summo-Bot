#include <SharpIR.h>

// Define model and input pin:
#define IRPin A0 // for left sharp
#define IRPin2 A1 // for Right sharp
#define model 20150
SharpIR mySensor = SharpIR(IRPin, model);
SharpIR mySensor2 = SharpIR(IRPin2, model);
int distance_cm;
int distance_cm2;

int MotorLeft1=6 ;
int MotorLeft2=9 ;
int MotorRight1=10 ;
int MotorRight2=11 ;
int photoElectric = 7;
int photoElectric2 = 8;
int BS=0;
int LTFrontLeft= 4; //front left
int LTFrontRight= 3; //front right
int LTBackLeft= 5; //back left
int LTBackRight= 2;
int delayT =800;

void setup() {
  // put your setup code here, to run once:
pinMode(MotorRight1, OUTPUT);
  pinMode(MotorRight2, OUTPUT);
  pinMode(MotorLeft1, OUTPUT);
  pinMode(MotorLeft2, OUTPUT);
  pinMode(photoElectric, INPUT);
pinMode(photoElectric2, INPUT);
pinMode(12,INPUT_PULLUP);
pinMode(LTFrontLeft, INPUT);
  pinMode(LTFrontRight, INPUT);
  pinMode(LTBackLeft, INPUT);
  pinMode(LTBackRight, INPUT);
  
 Serial.begin(9600);



delay(200);





}

void loop() {
distance_cm = mySensor.distance();
distance_cm2 = mySensor2.distance();


  if (digitalRead(12)==LOW && BS==0){
  BS=1;
  delay(5000);
  digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
    delay(400);
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
  }
  else if(digitalRead(12)==LOW && BS==1){
  BS=0;
  delay(200);
}
if(BS==1){



if(digitalRead(LTFrontLeft) == HIGH && digitalRead(LTFrontRight) == HIGH && digitalRead(LTBackRight) == HIGH && digitalRead(LTBackLeft) == HIGH ){

  if(digitalRead(photoElectric)== LOW || digitalRead(photoElectric2)==LOW){
  Serial.println("forward");
  digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
  }
  else if(digitalRead(photoElectric)== HIGH && digitalRead(photoElectric2)==HIGH){
  if (distance_cm<90){
    Serial.println("Sharp left");
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
    delay(600);
    
 }
 else if(distance_cm2<90){
    Serial.println("Sharp Right");
   digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
   
   
    delay(600);
    
 }
 else if (digitalRead(photoElectric)== HIGH && digitalRead(photoElectric2)==HIGH){
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
  }
  }
  
  }

  
else if(digitalRead(LTFrontLeft) == HIGH && digitalRead(LTFrontRight) == LOW )//white low
  {
    Serial.println("Front Left");
digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
delay(600);
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
    delay(delayT);
  }
  else if(digitalRead(LTFrontRight) == HIGH && digitalRead(LTFrontLeft) == LOW)
  {
    Serial.println("Front Right");
digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
delay(600);

    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
    delay(delayT);
  }
  else if(digitalRead(LTBackRight) == HIGH && digitalRead(LTFrontLeft) == LOW && digitalRead(LTFrontRight) == LOW )
  {
    Serial.println("back right");
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
    delay(delayT);
  }

else if(digitalRead(LTBackLeft) == HIGH && digitalRead(LTBackRight) == LOW && digitalRead(LTFrontLeft) == LOW && digitalRead(LTFrontRight) == LOW )
  {
    Serial.println("Back Left");
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
    delay(delayT);
  }
  

}
else {
  Serial.print("I'm OFF");
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,LOW);
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,LOW);
}
}
