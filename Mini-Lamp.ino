/* Libraries */
#include <Adafruit_NeoPixel.h>

/* Global variables and defines */
int Power = 11;   //select builtin rgb led
int PIN  = 12;    //data I think
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/*  */
void setup() {
  Serial.begin(115200); //config serial output for debugging
  while (!Serial);
  
  pixels.begin(); //start neopixels
  pinMode(Power,OUTPUT);
  digitalWrite(Power, HIGH);
}

/*  */
void loop() { 
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(15, 25, 205)); //blue
  delay(400);
  pixels.show();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(103, 25, 205));  //purple
  delay(400);
  pixels.show();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(233, 242, 205)); //light green
  delay(400);
  pixels.show();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(233, 23, 23)); //red
  delay(400);
  pixels.show();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(12, 66, 101)); //dark blue
  delay(400);
  pixels.show();
  delay(500);

}
