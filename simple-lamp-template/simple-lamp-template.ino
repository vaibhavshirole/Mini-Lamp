/* Libraries */
#include "src/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

/* Global variables and defines */
#define   NEOPIXEL            0          //say how many RGB LEDs we have
int       ENABLE_INTERNAL =   11;        //power the internal neopixel
int       RGB_DATA_IN =       12;        //address the internal neopixel
const int potentiometer =     A0;        //pin that the poteniometer is on

/* Built-in NeoPixel RGB LED needs an object to be declared to work */
Adafruit_NeoPixel pixels(NEOPIXEL+1, RGB_DATA_IN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  /* Configure serial output for debugging */
  Serial.begin(115200);
  delay(10);
  
  /* Start the built-in NeoPixel RGB LED */
  pixels.begin();
  pixels.show();
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);
  
  /* Start the pin that the potentiometer is connected to */
  pinMode(potentiometer, INPUT);
}


//void pixelsColorCycle(int changeDelay, int cycleThreshold){
//
//    /* Sets every NeoPixel to the specified color cycle */
//    for (int j=0; j<1024; j++){
//      int brightness = 255;
//      
//      setPixels(j, brightness);
//      pixels.show();
//
//      Serial.print("Current value being sent to setPixels: ");
//      Serial.println(j);
//      
//      delay(changeDelay);   //milliseconds
//
//      /* Check to see if potentiometer is out of the cycle threshold */
//      int potentiometerPosition = analogRead(potentiometer);
//      if(potentiometerPosition > cycleThreshold){
//        return;
//      }
//      
//    }
//    
//}


void loop(){
  /* Define the off and color cycle thresholds. These are between 0-1024 */
  int offValue = 500;                                  //turned to the left

  /* Get the value of the potentiometer */
  int potentiometerPosition = analogRead(potentiometer);    //read potentiometer value
  Serial.println(potentiometerPosition);                    //tell us potentiometer value

  uint32_t red = pixels.Color(255, 0, 0);
  uint32_t green = pixels.Color(0, 255, 0);
  uint32_t blue = pixels.Color(0, 0, 255);

  pixels.setBrightness(255);
  
  if(potentiometerPosition > offValue)
  {
    pixels.setPixelColor(NEOPIXEL, red);
  }
  else
  {
    pixels.clear();
  }
  
  pixels.show();
  
}
