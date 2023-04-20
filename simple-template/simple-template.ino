/* Libraries */
#include "src/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

/* Global variables and defines */
#define   NEOPIXEL            0          //say how many RGB LEDs we have
int       ENABLE_INTERNAL =   11;        //power the internal neopixel
int       RGB_DATA_IN =       12;        //address the internal neopixel
// TO-DO #1: Write the code to connect the pin to the potentiometer

/* Built-in NeoPixel RGB LED needs an object to be declared to work */
Adafruit_NeoPixel pixels(NEOPIXEL+1, RGB_DATA_IN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  /* Configure serial output for debugging */
  Serial.begin(115200);
  delay(10);
  
  // TO-DO #2: Write pixels.begin(); to start the NeoPixel
  pinMode(ENABLE_INTERNAL, OUTPUT);
  digitalWrite(ENABLE_INTERNAL, HIGH);
  
  // TO-DO #3: Start the pin that the potentiometer is connected to
  
}

int i;
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
  // Want your own color? https://www.colorspire.com/rgb-color-wheel/
                           // R   G   B
  uint32_t red = pixels.Color(255, 0, 0);
  uint32_t green = pixels.Color(0, 255, 0);
  uint32_t blue = pixels.Color(0, 0, 255);

  /* Define the off and color cycle thresholds. These are between 0-1024 */
  int offValue = 500;                                  //turned to the left

  /* Get the value of the potentiometer */
  // TO-DO #4: Get the value of the potentiometer
  // TO-DO #5: Display the value of the potentiometer on the Serial Monitor

  pixels.setBrightness(255);

  // TO-DO #6: Use the potentiometer to turn the LED on and off
  
}
