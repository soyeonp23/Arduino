#include "pitches.h"

int redLED = 13;
int greenLED = 12;
int blueLED = 11;

int buttonPin1 = 3;
int buttonPin2 = 4;

int melody[] = {
  NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_C5, NOTE_G4, NOTE_F4, 0, NOTE_D4, NOTE_E4, 
  NOTE_F4, NOTE_D5, NOTE_F4, NOTE_E4, 0, NOTE_C4, NOTE_D4, 
  NOTE_E4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_FS4, 
  NOTE_G4, 0, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_C5, NOTE_G4, NOTE_F4, 0, NOTE_D4, NOTE_E4, 
  NOTE_F4, NOTE_D5, NOTE_F4, NOTE_E4, 0, NOTE_G4, 
  NOTE_C5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_F5, NOTE_D5, 
  NOTE_B4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_F4, 0, NOTE_B4, NOTE_C5, 
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_E4, 0, NOTE_A4, NOTE_B4, 
  NOTE_C5, NOTE_C5, NOTE_B4, NOTE_A4, 
  NOTE_B4, 0, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_F4, 0, NOTE_B4, NOTE_C5, 
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, 0, NOTE_D5, NOTE_E5, 
  NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_B4, 
  NOTE_C5, 0
  
};

int noteDurations[] = {
  16,16,
  8,8,8,8,8,16,16,
  8,8,8,8,8,16,16,
  8,8,8,4,8,
  3,4,16,16,
  8,8,8,8,8,16,16,
  8,8,8,8,8,8,
  8,8,8,8,6,16,
  4,16,16,8,8,16,16,
  8,8,8,8,8,16,16,
  6,16,8,8,8,16,16,
  4,8,4,8,
  3,4,16,16,
  8,8,8,8,8,16,16,
  6,16,8,8,8,16,16,
  6,16,8,8,8,8,
  3,4
};

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void music() {
  for (int i = 0; i < 95; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(8, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    while (digitalRead(buttonPin1) == LOW) {
      digitalWrite(redLED, HIGH); 
    }
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    music();
    digitalWrite(blueLED, LOW);
  }
  if (digitalRead(buttonPin2) == LOW) {
    digitalWrite(greenLED, HIGH);
    while (digitalRead(buttonPin1) == LOW) {
      // Keep the green LED on as long as the button is pressed
    }
    digitalWrite(greenLED, LOW);
  }
}