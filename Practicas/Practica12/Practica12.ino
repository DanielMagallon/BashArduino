#include "pitches.h"

int pinModes[] = {8,9,10};
int pinBuzzer = 7;
int currentLed,auxLed;

void setup(void)
{
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);//buzzer
  
  for(int i=0; i<3; i++)
  {
    pinMode(pinModes[i],OUTPUT);
    digitalWrite(pinModes[i], LOW);
  }

  auxLed=-1;
}

void playSound8()
{
  int melody[] = {
    NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
      4, 8, 8, 4,4,4,4,4 };
  
   for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(pinBuzzer, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinBuzzer);
  }
}


void playSound9()
{
    int melody[] = {
    NOTE_E1, NOTE_G3,NOTE_B3, NOTE_E4, NOTE_E1, NOTE_G3,NOTE_B3, NOTE_E4};

    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[] = {
          4, 2, 2, 2,4,2,2,2 };
  
   for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(pinBuzzer, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinBuzzer);
  }
}

void playSound10()
{

    int melody[] = {
        NOTE_E1, NOTE_G3,NOTE_B3, NOTE_E4, NOTE_E1, NOTE_G3,NOTE_B3, NOTE_E4};

    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[] = {
          2, 8, 8, 4,4,2,8,2 };
  
   for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(pinBuzzer, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinBuzzer);
  }
}

void loop()
{

  if(Serial.available())
  {
    currentLed = Serial.parseInt();
    if(currentLed>=8 && currentLed <= 10)
    {
      if(auxLed!=-1)
        digitalWrite(auxLed, LOW);  
      
      auxLed = currentLed;
      digitalWrite(currentLed, HIGH);

      switch(currentLed)
      {
        case 8:
          playSound8();
          break;

        case 9:
        playSound9();
          break;

        case 10:
        playSound10();
          break;
      }
    }

    delay(700);
  }
}
