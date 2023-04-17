//==================//==================//==================//==================//
/* DECLARATIONS: */

/* Libraries */
#include "src/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

/* Global variables and defines */
#define   NUM_NEOPIXELS       1          /* say how many RGB LEDs we have */
int       ENABLE_INTERNAL =   11;        /* power the internal neopixel */
int       RGB_DATA_IN =       12;        /* address the internal neopixel */
const int potentiometer =     // TO-DO: Find the pin that the potentiometer is connected to

// TO-DO: Create the “pixels” object that lets you control the light on the microcontroller

//==================//==================//==================//==================//
/* SETUP FUNCTIONS: */

/*   
 *    This function is very important.
 *    It configures everything so that 
 *    you can use everything together when
 *    the program is running.
 */
void setup() {
  
  /* Configure serial output for debugging */
  Serial.begin(115200);
  delay(10);
  
  /* Start the built-in NeoPixel RGB LED */
  pixels.begin();
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);
  
  // TO-DO: Start the pin that the potentiometer is connected to */
}


//==================//==================//==================//==================//
/* HELPER FUNCTIONS: */

/* 
 *  Helper function:
 *    Call this function to change the color of the NeoPixel
 *
 *  Want a specific color?
 *  -> Call setPixels and give it a number in the desired range:
 *      ORANGE:         0-100
 *      YELLOW:         100 to 200
 *      GREEN:          200 to 300
 *      TURIOISE:       300 to 400
 *      LIGHT BLUE:     400 to 500
 *      BLUE:           500 to 600
 *      DARK BLUE:      600 to 700
 *      PURPLE:         700 to 800
 *      PINK:           800 to 900
 *      DARK PINK:      900 to 1000
 *      RED:            1000 to 1024
 */
void setPixels(int color, long unsigned brightness){

  /* Sets every NeoPixel to the color and brightness you chose */
  for (int i=0; i<NUM_NEOPIXELS; i++){
    brightness*=brightness;
    brightness/=255;
    pixels.setPixelColor(i, pixels.ColorHSV(color*64, 255, brightness));
  }
  pixels.show();        /* Make changes visible on the NeoPixel */
}


/*
 * Helper function: 
 *    Turns the lights off on the NeoPixel
 */
void pixelsOff(void){
  
  /* Sets every NeoPixel to off */
  // TO-DO: Fill the whole NeoPixel strip with 0 / black / off
  // TO-DO: Transmit pixel data in RAM to NeoPixels (basically, just make changes visible on the NeoPixel)
}


/*
 * Helper function:
 *    Cycles through all possible colors automatically
 */
void pixelsColorCycle(int changeDelay, int cycleThreshold){

    /* Sets every NeoPixel to the specified color cycle */
    for (int j=0; j<1024; j++){
      int brightness = 255;
      
      setPixels(j, brightness);
      pixels.show();                /* Make changes visible on the NeoPixel */

      Serial.print("Current value being sent to setPixels: ");
      Serial.println(j);
      
      delay(changeDelay);           /* Time in milliseconds */

      /* Check to see if potentiometer is out of the cycle threshold */
      int potentiometerPosition = analogRead(potentiometer);
      if(potentiometerPosition > cycleThreshold){
        return;
      }
      
    }
    
}


//==================//==================//==================//==================//
/* MAIN(): */

/*  
 *   This is the main function.
 *   It checks the value of the poteniometer,
 *   and then decides what color the NeoPixel
 *   should be.
*/
void loop(){
  
  /* Define the off and color cycle thresholds. These are between 0-1024 */
  int offThreshold = 1020;                                  /* turned all the way left */
  int cycleThreshold = 10;                                  /* turned all the way right */

  /* Get the value of the potentiometer */
  // TO-DO: Read potentiometer value
  // TO-DO: Tell us the potentiometer value on the Serial Monitor
  
  
  /* Check whether the potentiometer is turned to the left to turn off light */
  if ( // TO-DO: Turn off the NeoPixel when potentiometer is turned to the left ) 
  {
    pixelsOff();  // TO-DO: Finish this function
  }
  else if ( // TO-DO: Have the NeoPixel cycle through all colors when potentiometer is turned to the right )
  {
    int changeDelay = 100;                                  /* larger number means slower cycle */
    pixelsColorCycle(changeDelay, cycleThreshold);
  }
  else
  {
    long unsigned brightness = 255;
    setPixels(potentiometerPosition, brightness);           /* change neopixel colors with potentiometer */  
  }
    
}
