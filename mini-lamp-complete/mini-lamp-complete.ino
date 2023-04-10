//==================//==================//==================//==================//
// DECLARATIONS: 

/* Libraries */
#include "src/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

/* Global variables and defines */
#define   NUM_NEOPIXELS       1          //say how many RGB LEDs we have
int       ENABLE_INTERNAL =   11;        //power the internal neopixel
int       RGB_DATA_IN =       12;        //address the internal neopixel
const int potentiometer =     A0;        //pin that the poteniometer is on

/* Built-in NeoPixel RGB LED needs an object to be declared to work */
Adafruit_NeoPixel pixels(NUM_NEOPIXELS, RGB_DATA_IN, NEO_GRB + NEO_KHZ800);


//==================//==================//==================//==================//
// SETUP FUNCTIONS: 

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
  
  /* Start the pin that the potentiometer is connected to */
  pinMode(potentiometer, INPUT);
}


//==================//==================//==================//==================//
// HELPER FUNCTIONS: 

/* 
 *  Helper function:
 *    Call this function to change the color of the NeoPixel
 *
 *  Want a specific color?
 *  -> Call setPixels and give it a number in the desired range:
 *      ORANGE:         0-100
 *      YELLOW:         100-200
 *      GREEN:          200-300
 *      TURIOISE:       300-400
 *      LIGHT BLUE:     400-500
 *      BLUE:           500-600
 *      DARK BLUE:      600-700
 *      PURPLE:         700-800
 *      PINK:           800-900
 *      DARK PINK:      900-1000
 *      RED:            1000-1024
 */
void setPixels(int color, long unsigned brightness){

  /* Sets every NeoPixel to the color and brightness you chose */
  for (int i=0; i<NUM_NEOPIXELS; i++){
    brightness*=brightness;
    brightness/=255;
    pixels.setPixelColor(i, pixels.ColorHSV(color*64, 255, brightness));
  }
  pixels.show();
}


/*
 * Helper function: 
 *    Turns the lights off on the NeoPixel
 */
void pixelsOff(void){
  
  /* Sets every NeoPixel to off */
  pixels.clear();
  pixels.show();
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
      pixels.show();

      Serial.print("Current value being sent to setPixels: ");
      Serial.println(j);
      
      delay(changeDelay);   //milliseconds

      /* Check to see if potentiometer is out of the cycle threshold */
      int potentiometerPosition = analogRead(potentiometer);
      if(potentiometerPosition > cycleThreshold){
        return;
      }
      
    }
    
}


//==================//==================//==================//==================//
// MAIN():

/*  
 *   This is the main function.
 *   It checks the value of the poteniometer,
 *   and then decides what color the NeoPixel
 *   should be.
*/
void loop(){
  
  /* Define the off and color cycle thresholds. These are between 0-1024 */
  int offThreshold = 1020;                                  //turned all the way left
  int cycleThreshold = 10;                                  //turned all the way right

  /* Get the value of the potentiometer */
  int potentiometerPosition = analogRead(potentiometer);    //read potentiometer value
  Serial.println(potentiometerPosition);                    //tell us potentiometer value
  
  
  /* Check whether the potentiometer is turned to the left to turn off light */
  if (potentiometerPosition > offThreshold) 
  {
    pixelsOff();
  }
  else if (potentiometerPosition < cycleThreshold)
  {
    int changeDelay = 100;                                  //larger number means slower cycle
    pixelsColorCycle(changeDelay, cycleThreshold);
  }
  else
  {
    long unsigned brightness = 255;
    setPixels(potentiometerPosition, brightness);           //change neopixel colors with potentiometer   
  }
    
}
