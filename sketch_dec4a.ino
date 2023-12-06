#include "pitches.h"
int note1 = 2;
int note2 = 3;
int note3 = 4;
int note4 = 5;
int note5 = 6;
int note6 = 7;
int note7 = 8;
int note8 = 9;
int note9 = 10;
int note10 = 11;
int buzzer = 13;
int in = 0;
int mode = 0;


enum ModeStates{ off,tones1, tones2, tones3, record} states;

void keyboard_mode(){

  switch(states){
    case off:
    Serial.println("apple");
      states = tones1;
      break;
    case tones1:
    if(mode == 0){
      Serial.println("apple");
      states = tones1;
    }else if(mode == 1){
      states = tones2;
    }else if(mode == 2){
      states = tones3;
    }else if(mode == 3){
      states = record;
    }
    break;

    case tones2:
    if(mode == 0){
      states = tones1;
    }else if(mode == 1){
      states = tones2;
    }else if(mode == 2){
      states = tones3;
    }else if(mode == 3){
      states = record;
    }
    break;

    case tones3:
    if(mode == 0){
      states = tones1;
    }else if(mode == 1){
      states = tones2;
    }else if(mode == 2){
      states = tones3;
    }else if(mode == 3){
      states = record;
    }
    break;

    case record:
    if(mode == 0){
      states = tones1;
    }else if(mode == 1){
      states = tones2;
    }else if(mode == 2){
      states = tones3;
    }else if(mode == 3){
      states = record;
    }
    break;
  }


  switch(states){
    case off:
      states = tones1;
      break;
    case tones1:
    if(digitalRead(note1) == HIGH){
    tone(buzzer, NOTE_E5, 100);
  }
  if(digitalRead(note2) == HIGH){
    tone(buzzer, NOTE_F5, 100);
  }

  if(digitalRead(note3) == HIGH){
    tone(buzzer, NOTE_D5, 100);
  }
  if(digitalRead(note4) == HIGH){
    tone(buzzer, NOTE_C5, 100);
  }
  if(digitalRead(note5) == HIGH){
    tone(buzzer, NOTE_G5, 100);
  }
  if(digitalRead(note6) == HIGH){
    tone(buzzer, NOTE_A5, 100);
  }
  if(digitalRead(note7) == HIGH){
    tone(buzzer, NOTE_B5, 100);
  }
  if(digitalRead(note8) == HIGH){
    tone(buzzer, NOTE_C6, 100);
  }
  if(digitalRead(note9) == HIGH){
    tone(buzzer, NOTE_D6, 100);
  }
  if(digitalRead(note10) == HIGH){
    tone(buzzer, NOTE_E6, 100);
  }
    break;

    case tones2:

    Serial.println("apple");
  if(digitalRead(note1) == HIGH){
    tone(buzzer, NOTE_C2, 100);
  }
  if(digitalRead(note2) == HIGH){
    tone(buzzer, NOTE_D2, 100);
  }

  if(digitalRead(note3) == HIGH){
    tone(buzzer, NOTE_E2, 100);
  }
  if(digitalRead(note4) == HIGH){
    tone(buzzer, NOTE_F2, 100);
  }
  if(digitalRead(note5) == HIGH){
    tone(buzzer, NOTE_G2, 100);
  }
  if(digitalRead(note6) == HIGH){
    tone(buzzer, NOTE_A2, 100);
  }
  if(digitalRead(note7) == HIGH){
    tone(buzzer, NOTE_B2, 100);
  }
  if(digitalRead(note8) == HIGH){
    tone(buzzer, NOTE_C3, 100);
  }
  if(digitalRead(note9) == HIGH){
    tone(buzzer, NOTE_D3, 100);
  }
  if(digitalRead(note10) == HIGH){
    tone(buzzer, NOTE_E3, 100);
  }
    break;

    case tones3:
    if(digitalRead(note1) == HIGH){
    tone(buzzer, NOTE_A3, 100);
  }
  if(digitalRead(note2) == HIGH){
    tone(buzzer, NOTE_B3, 100);
  }

  if(digitalRead(note3) == HIGH){
    tone(buzzer, NOTE_C4, 100);
  }
  if(digitalRead(note4) == HIGH){
    tone(buzzer, NOTE_D4, 100);
  }
  if(digitalRead(note5) == HIGH){
    tone(buzzer, NOTE_E4, 100);
  }
  if(digitalRead(note6) == HIGH){
    tone(buzzer, NOTE_F4, 100);
  }
  if(digitalRead(note7) == HIGH){
    tone(buzzer, NOTE_G4, 100);
  }
  if(digitalRead(note8) == HIGH){
    tone(buzzer, NOTE_A4, 100);
  }
  if(digitalRead(note9) == HIGH){
    tone(buzzer, NOTE_B4, 100);
  }
  if(digitalRead(note10) == HIGH){
    tone(buzzer, NOTE_C5, 100);
  }
    break;

    case record:
    if(digitalRead(note1) == HIGH){
    tone(buzzer, NOTE_E5, 100);
  }
  if(digitalRead(note2) == HIGH){
    tone(buzzer, NOTE_F5, 100);
  }

  if(digitalRead(note3) == HIGH){
    tone(buzzer, NOTE_D5, 100);
  }
  if(digitalRead(note4) == HIGH){
    tone(buzzer, NOTE_C5, 100);
  }
  if(digitalRead(note5) == HIGH){
    tone(buzzer, NOTE_G5, 100);
  }
  if(digitalRead(note6) == HIGH){
    tone(buzzer, NOTE_A5, 100);
  }
  if(digitalRead(note7) == HIGH){
    tone(buzzer, NOTE_B5, 100);
  }
  if(digitalRead(note8) == HIGH){
    tone(buzzer, NOTE_C6, 100);
  }
  if(digitalRead(note9) == HIGH){
    tone(buzzer, NOTE_D6, 100);
  }
  if(digitalRead(note10) == HIGH){
    tone(buzzer, NOTE_E6, 100);
  }
    break;
  }


}

void setup() {
pinMode(note1,INPUT);
pinMode(note2,INPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
states = off;
}

void loop() {

  in = analogRead(A0);
  mode = map(in, 0, 1023, 0, 3);
  //Serial.println(mode);

  keyboard_mode();

  

}
