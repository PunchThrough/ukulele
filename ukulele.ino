/* 
  This sketch is used to play a piezo buzzer ukulele. 
  
  It is intended to be used with the LightBlue Bean.
      
  This example code is in the public domain.
*/

#include <CapacitiveSensor.h>

#define COMMON_PIN  5    // The common 'send' pin for all strings
#define BUZZER_PIN  4  // The pin connected to the piezo buzzer
#define THRESHOLD  100  // Capactive reading that triggers a note
#define NUM_OF_STRINGS     4    // Number of strings on the ukulele

#define CS(Y) CapacitiveSensor(COMMON_PIN, Y)

// The pins that are connected to the strings
CapacitiveSensor strings[] = {CS(0), CS(1), CS(2), CS(3)};

// Corresponds to tones D5, G4, B4, E5
int notes[] = {587, 392, 494, 659};

void setup() { 
  for(int i=0; i < NUM_OF_STRINGS; ++i) {
    strings[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {    
  for (int i = 0; i < NUM_OF_STRINGS; ++i) {
    // Check if the capacitance is over the threshold
    if(strings[i].capacitiveSensor(10) > THRESHOLD) {
      // Play the corresponding tone
      tone(BUZZER_PIN, notes[i]);
      delay(100);
      noTone(BUZZER_PIN);
    }
  }
  Bean.sleep(100);
}
