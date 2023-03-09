/* Libraries */
#include <Adafruit_NeoPixel.h>

/* Global variables and defines */
int ENABLE_INTERNAL = 11;   //power the internal neopixel
int RGB_DATA_IN  = 12;    //address the internal neopixel
#define NUM_NEOPIXELS 1

const int sensorPin = A0; //pin that the poteniometer is on
const int ledPin = 25;    //onboard blue LED for debugging

/* Built-in NeoPixel RGB LED needs an object to be declared to work */
Adafruit_NeoPixel pixels(NUM_NEOPIXELS, RGB_DATA_IN, NEO_GRB + NEO_KHZ800); //initialize neopixels object


/*   
 *    This function is very important.
 *    It configures everything so that 
 *    you can use everything together when
 *    the program is running.
 */
void setup() {
  
  /* Configure serial output for debugging */
  Serial.begin(115200);
  while (!Serial);

  
  /* Start the built-in NeoPixel RGB LED */
  pixels.begin(); //start neopixels
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);

  
  /* Start the pin that the potentiometer is connected to */
  pinMode(sensorPin, INPUT);

  
  /* Start an on-board blue LED for debugging */
  pinMode(ledPin, OUTPUT);
}


/* 
 *  Helper function to handle color 
 *  changing using the potentiometer 
 */
void setPixel(int pixel, int color, long unsigned brightness){
  brightness*=brightness;
  brightness/=255;
  pixels.setPixelColor(pixel, pixels.ColorHSV(color*64, 255, brightness));
}


/*  
 *   This is the main function.
 *   It checks the value of the poteniometer,
 *   and then decides what color the NeoPixel
 *   should be.
*/
void loop(){

  //read potentiometer value
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);    //between 0 and 1024

  //change neopixel colors with potentiometer
  for(int i=0; i<NUM_NEOPIXELS; i++){
    setPixel(i, sensorValue, 255);
  }
  pixels.show();

}
