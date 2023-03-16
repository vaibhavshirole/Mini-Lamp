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
  /*
  Want a specific color?
  Call this function and give it a number in the desired range...
    ORANGE:         0-100
    YELLOW:         100-200
    GREEN:          200-300
    TURIOISE:       300-400
    LIGHT BLUE:     400-500
    BLUE:           500-600
    DARK BLUE:      600-700
    PURPLE:         700-800
    PINK:           800-900
    DARK PINK:      900-1000
    RED:            1000-1024
  */
  
  
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
void pixelColorCycle(int fade_speed, int cycleValue){ 
  for (int j=0; j<1024; j++){    
    for (int i=0; i<NUM_NEOPIXELS; i++){
      setPixel(i, j, 255);
    }
    pixels.show();

    Serial.print("Current value being sent to setPixel: ");
    Serial.println(j);
    
    delay(fade_speed);
    
    int sensorValue = analogRead(sensorPin);
    if( sensorValue > cycleValue){
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
  int offValue = 1020;                            //potentiometer turned all the way left
  int cycleValue = 6;                             //potentiometer turned all the way right

  /* On (0) */
  digitalWrite(ledPin, LOW);                      //toggle built-in LED
  
  int sensorValue = analogRead(sensorPin);        //read potentiometer value
  Serial.println(sensorValue);                    //between 0 and 1024

  /* Check whether the potentiometer is turned to the left to turn off light */
  if (sensorValue > offValue) {
    pixelOff();
    
  }
  else if (sensorValue < cycleValue){
    int speed = 100;                              //a larger number here means slower cycle
    pixelColorCycle(speed, cycleValue);
             
  }
  else
  {
    for (int i=0; i<NUM_NEOPIXELS; i++){
      setPixel(i, sensorValue, 255);              //change neopixel colors with potentiometer
    }
    pixels.show();
    
  }
    
}
