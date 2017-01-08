/* 
 * Teensy 3.1 or 3.2 
 * 10 LED Chase
 *
 */

// Total Number of LEDs
const int MAXLEDS = 10;

// Delays
const int FIRSTDELAY = 75;
const int SECONDDELAY = 10;

// Brightness Levels
const int LEDFULL = 255;
const int LED50PER = 128;
const int LED6PER = 16;
const int LEDOFF = 0;


// Output pins on Teensy
const int LEDPINS[MAXLEDS] = {
  3, 4, 5, 6, 9, 10, 20, 21, 22, 23
};

void setup() {
  // initialize LEDPINS for output
  for (int lpin = 0; lpin < MAXLEDS; lpin++) {
    pinMode(LEDPINS[lpin], OUTPUT);
  }

}

void loop() {
  // Cycle through all 10 LEDs:
  for (int ld = 0; ld < MAXLEDS; ld++) {

    // Main LED, turn on 
    analogWrite(LEDPINS[ld], LEDFULL);
    // First chasing LED, turn on
    if (ld - 1 > 0) {
      analogWrite(LEDPINS[ld - 1], LED50PER);
    }
    // Second Chasing LED, turn on
    if (ld - 2 > 0) {
      analogWrite(LEDPINS[ld - 2], LED6PER);
    }
    
    delay(FIRSTDELAY);
    
    analogWrite(LEDPINS[ld], LEDOFF);
    if (ld - 1 > 0) {
      analogWrite(LEDPINS[ld - 1], LEDOFF);
    }
    if (ld - 2 > 0) {
      analogWrite(LEDPINS[ld - 2], LEDOFF);
    }
    
    delay(SECONDDELAY);
  }

  // reverse direction
  for (int ld = MAXLEDS; ld >= 0; ld--) {
    analogWrite(LEDPINS[ld], LEDFULL);
    if (ld + 1 < MAXLEDS) {
      analogWrite(LEDPINS[ld + 1], LED50PER);
    }
    if (ld + 2 < MAXLEDS) {
      analogWrite(LEDPINS[ld + 2], LED6PER);
    }
    
    delay(FIRSTDELAY);
    
    analogWrite(LEDPINS[ld], LEDOFF);
    if (ld + 1 < MAXLEDS) {
      analogWrite(LEDPINS[ld + 1], LEDOFF);
    }
    if (ld + 2 < MAXLEDS) {
      analogWrite(LEDPINS[ld + 2], LEDOFF);
    }
    
    delay(SECONDDELAY);
  }

}
