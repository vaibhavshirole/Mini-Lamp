/* Libraries */
#include <Adafruit_NeoPixel.h>

/* Global variables and defines */
int ENABLE_INTERNAL = 11;           //power the internal neopixel
int RGB_DATA_IN  = 12;              //address the internal neopixel
#define NUM_NEOPIXELS 1

const int sensorPin = A0;           //pin that the poteniometer is on
const int ledPin = 25;              //onboard blue LED for debugging

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
  Serial.begin(115200);                   //start monitoring at 115,200 baud
  delay(10);                              //delay to guarantee stuff shows in your monitor
  
  /* Start the built-in NeoPixel RGB LED */
  pixels.begin();
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);
  
  /* Start the pin that the potentiometer is connected to */
  pinMode(sensorPin, INPUT);

  /* Start an on-board blue LED for debugging */
  pinMode(ledPin, OUTPUT);
}

//==================//==================//==================//==================//
// HELPER FUNCTIONS: 

/* 
 *  Helper function:
 *    Handles color changing using the potentiometer 
 */
void setPixel(int pixel, int color, long unsigned brightness){
  brightness*=brightness;
  brightness/=255;
  pixels.setPixelColor(pixel, pixels.ColorHSV(color*64, 255, brightness));
}


/*
 * Helper function: 
 *    Turns the lights off on the NeoPixel
 */
void pixelOff(void){
  digitalWrite(ledPin, HIGH);                     //toggle built-in LED
  
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); //turn neopixel off
  pixels.show();
}


/*
 * Helper function:
 *    Cycles through all possible colors
 */
void pixelColorCycle(int speed){
  ////////////////////////////// TO-DO: IMPLEMENT THIS METHOD SO THAT IT CYCLES THROUGH RAINBOW
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

  /* On (0) */
  digitalWrite(ledPin, LOW);                      //toggle built-in LED
  
  int sensorValue = analogRead(sensorPin);        //read potentiometer value
  Serial.println(sensorValue);                    //between 0 and 1024

  /* Check whether the potentiometer is turned all the way to right to turn off light */
  if (sensorValue < 10) {
    pixelOff();
    
  }
  else if (sensorValue > 1015){
    pixelColorCycle(10); 
         
  }
  else
  {
    for (int i=0; i<NUM_NEOPIXELS; i++){
      setPixel(i, sensorValue, 255);               //change neopixel colors with potentiometer
    }
    pixels.show();  
    
  }
    
  return 0;
}
