/* Libraries */
#include <Adafruit_NeoPixel.h>

/* Global variables and defines */
int ENABLE_INTERNAL = 11;           //power the internal neopixel
int RGB_DATA_IN  = 12;              //address the internal neopixel
#define NUM_NEOPIXELS 1

const int sensorPin = A0;           //pin that the poteniometer is on
const int ledPin = 25;              //onboard blue LED for debugging

const int switchPin = D1;           //pin that the switch is on
int state = 0;                      //keeps track of whether the system is on or off

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
  while (!Serial);          //TO-DO: DELETE THIS AND REPLACE WITH JUST A DELAY SO THAT THIS WORKS WITHOUT SERIAL MONITOR
  
  /* Start the built-in NeoPixel RGB LED */
  pixels.begin(); //start neopixels
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);
  
  /* Start the pin that the potentiometer is connected to */
  pinMode(sensorPin, INPUT);

  /* Start the pin that the switch is connected to */
  pinMode(switchPin, INPUT);
  
  /* Start an on-board blue LED for debugging */
  pinMode(ledPin, OUTPUT);
}

//==================//==================//==================//==================//
// HELPER FUNCTIONS: 

/* 
 *  Helper function to handle color 
 *  changing using the potentiometer 
 */
void setPixel(int pixel, int color, long unsigned brightness){
  brightness*=brightness;
  brightness/=255;
  pixels.setPixelColor(pixel, pixels.ColorHSV(color*64, 255, brightness));
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

  //TO-DO: 
  //  ADD MODE SO THAT WHEN IT TURNS ALL THE WAY TO THE LEFT IT CYCLES THROUGH THE COLORS ON ITS OWN.
  //  HOW IT SHOULD WORKS: IS IT GOES THROUGH EVERY COLOR, HIGHER VALUES AS YOU TURN TO LEFT
  //  AND LOWER VALUES AS YOU TURN TO RIGHT. ALL THE WAY TO RED WIRE, IT TURNS OFF. ALL THE WAY
  //  TO LEFT IT CYCLES THROUGH COLORS AUTOMATICALLY

    /* On (0) */
    digitalWrite(ledPin, LOW);                      //toggle built-in LED
    
    int sensorValue = analogRead(sensorPin);        //read potentiometer value
    Serial.println(sensorValue);                    //between 0 and 1024

    /* Check whether the potentiometer is turned all the way to right to turn off light */
    if(sensorValue < 10) {
      /* Off (1) */
      digitalWrite(ledPin, HIGH);                     //toggle built-in LED
      
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 0)); //turn neopixel off
      pixels.show();
    }
    else
    {
      for(int i=0; i<NUM_NEOPIXELS; i++){
        setPixel(i, sensorValue, 255);                //change neopixel colors with potentiometer
      }
      pixels.show();  
    }
}
