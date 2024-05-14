#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int a=0;
int b=0;
int ENA=5;
int ENB=6;
int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;

void setup() {
  Serial.begin(250000);      
  Dabble.begin(9600);  
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  Dabble.processInput();            
  a = GamePad.getAngle();
  b = GamePad.getRadius();
  Serial.print("Ángulo= ");
  Serial.println(a);
  if(a==0){                           //Parado
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
  }
    if(a==0 && b>1){                  //Derecha
      digitalWrite(ENA,HIGH);
      digitalWrite(ENB,HIGH);
      analogWrite(ENA,255);
      analogWrite(ENB,255);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==15){
      analogWrite(ENA,255);
      analogWrite(ENB,170);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==30){
      analogWrite(ENA,255);
      analogWrite(ENB,85);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==45){
      analogWrite(ENA,255);
      analogWrite(ENB,0);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      }
    if(a==60){
      analogWrite(ENA,255);
      analogWrite(ENB,170);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==75){
      analogWrite(ENA,255);
      analogWrite(ENB,85);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      } 
    if(a==90){                          //Adelante
      digitalWrite(ENA,HIGH);
      digitalWrite(ENB,HIGH);
      analogWrite(ENA,255);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
    }
    if(a==105){
      analogWrite(ENA,170);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==120){
      analogWrite(ENA,85);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==135){
      analogWrite(ENA,0);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      }
    if(a==150){
      analogWrite(ENA,255);
      analogWrite(ENB,170);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==165){
      analogWrite(ENA,255);
      analogWrite(ENB,85);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      } 
    if(a==180){                          //Izquierda
      digitalWrite(ENA,HIGH);
      digitalWrite(ENB,HIGH);
      analogWrite(ENA,255);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==195){
      analogWrite(ENA,255);
      analogWrite(ENB,170);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==210){
      analogWrite(ENA,255);
      analogWrite(ENB,85);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      }
    if(a==225){
      analogWrite(ENA,255);
      analogWrite(ENB,0);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==240){
      analogWrite(ENA,255);
      analogWrite(ENB,85);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==255){
      analogWrite(ENA,255);
      analogWrite(ENB,170);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      } 
  if(a==270){                          //Atrás
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    analogWrite(ENA,255);
    analogWrite(ENB,255);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
    if(a==285){
      analogWrite(ENA,170);
      analogWrite(ENB,255);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==300){
      analogWrite(ENA,85);
      analogWrite(ENB,255);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==315){
      analogWrite(ENA,0);
      analogWrite(ENB,255);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    if(a==330){
      analogWrite(ENA,85);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      } 
    if(a==345){
      analogWrite(ENA,170);
      analogWrite(ENB,255);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      }
    }