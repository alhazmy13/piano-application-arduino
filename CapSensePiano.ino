/*
  Arduino Piano
  
  Created  05 DEC 2014
  by Abdullah Alhazmy
  For more inforamtion vist: http://alhazmy13.net
  */

#include <CapacitiveSensor.h>
#include "pitches.h"

#define COMMON_PIN      2  
#define SPEEKER_PIN      11  
#define NUM_OF_SAMPLES  10   
#define CAP_THRESHOLD   150 
#define NUM_OF_KEYS     8   

#define CS(Y) CapacitiveSensor(2, Y)

int notes[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5}; // C-Major scale


CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9), CS(10)};

void setup() { 
  // Turn off on all channels:
  for(int i=0; i<8; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }

  pinMode(SPEEKER_PIN, OUTPUT); 
}

void loop() {    

  for (int i = 0; i < 8; ++i) {
    // play a note:
    if(keys[i].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD) {
      tone(SPEEKER_PIN, notes[i]); 
    }
  }
  pinMode(SPEEKER_PIN, OUTPUT); 

}
