#define CUSTOM_SETTINGS             //Incluimos la libreria y el Gamepad de la app
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#define NOTE_C4  262               //Definimos todas las notas musicales que usaremos
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define REST      0


int a=0;                          //Declaramos las variables de radio y ángulo
int b=0;
int ENA=5;                        //También las de los motores
int ENB=6;
int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;

int tempo = 120;                    //Toda esta estructura es para las canciones(copiada de Github como hemos explicado en el informe)
int buzzer = 12;
int melody[] = {
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,
};
int melody2[] = {
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, 
  NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,
  NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  
  NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
  NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
int notes2 = sizeof(melody2) / sizeof(melody2[0]) / 2;
int wholenote2 = (60000 * 4) / tempo;
int divider2 = 0, noteDuration2 = 0;



void setup() {                    //Comienzo del programa
  Serial.begin(250000);           //Asociamos los monitores por si queremos ver las salidas
  Dabble.begin(9600);  
  pinMode(ENA,OUTPUT);            //Asociamos los pines de los motores
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  Dabble.processInput();                      //Estos comandos nos sirven para recibir datos de la app
  a = GamePad.getAngle();
  b = GamePad.getRadius();
  Serial.print("Ángulo= ");                   //Por si queremos ver el ángulo en el monitor
  Serial.println(a);
  if(a==0){                                   //Parado
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
  }
  if(a==0 && b>1){                          //Derecha
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    analogWrite(ENA,150);
    analogWrite(ENB,100);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  if(a==270){                               //Atrás
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    analogWrite(ENA,150);
    analogWrite(ENB,150);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  if(a==180){                               //Izquierda
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    analogWrite(ENA,150);
    analogWrite(ENB,100);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
  if(a==90){                                  //Adelante
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    analogWrite(ENA,150);
    analogWrite(ENB,150);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
  if (GamePad.isSquarePressed()){                //Si pulsamos cuadrado, Marcha Imperial
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = melody[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } 
      else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5;
      }
      tone(buzzer, melody[thisNote], noteDuration*0.9);
      delay(noteDuration);
      noTone(buzzer);
    }
  }
  if (GamePad.isCirclePressed()){                   //Si pulsamos círculo, Pacman
    for (int thisNote2 = 0; thisNote2 < notes2 * 2; thisNote2 = thisNote2 + 2) {
      divider2 = melody2[thisNote2 + 1];
      if (divider2 > 0) {
        noteDuration2 = (wholenote2) / divider2;
      } 
      else if (divider2 < 0) {
        noteDuration2 = (wholenote2) / abs(divider2);
        noteDuration2 *= 1.5;
      }
      tone(buzzer, melody[thisNote2], noteDuration2*0.9);
      delay(noteDuration2);
      noTone(buzzer);
    }
  }
}

