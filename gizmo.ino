// Gizmo source code for Orpheus and Eurydice Zoetrope

//Import neopixel library
#include <Adafruit_NeoPixel.h>

//Define DC motors
#define MOTORUP_IN1 9
#define MOTORUP_IN2 10
#define MOTORDOWN_IN1 6
#define MOTORDOWN_IN2 5

//Initialize small neopixel strip
#define PIN 8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

//Initialize light sensor
int photocellPin=0; 
int photocellReading;

void setup() {
  
  //Setup outputs
  pinMode(MOTORUP_IN1, OUTPUT);
  pinMode(MOTORUP_IN2, OUTPUT);
  pinMode(MOTORDOWN_IN1, OUTPUT);
  pinMode(MOTORDOWN_IN2, OUTPUT);
  pinMode(7, OUTPUT);
  //Start short neopixel strip
  pixels.begin();
}
 
void loop() {

  //Read light level
  photocellReading=analogRead(photocellPin);

  //If lights are off, turn on
 if (photocellReading<100) 
{
 //motors
    digitalWrite(MOTORUP_IN2, 100);
    analogWrite(MOTORUP_IN1, LOW);
    digitalWrite(MOTORDOWN_IN2, 255);
    analogWrite(MOTORDOWN_IN1, LOW);
  //long neopixel
    digitalWrite(7, HIGH);
  //short neopixel
  for(int i=0;i<4;i++){
    pixels.setPixelColor(i, pixels.Color(95,0,255));
    pixels.show(); 
    delay(500);
    }
  }

  //If lights are on, turn off
  else 
  {
    //motors
    digitalWrite(MOTORUP_IN2, 0);
    analogWrite(MOTORUP_IN1, LOW);
    digitalWrite(MOTORDOWN_IN2, 0);
    analogWrite(MOTORDOWN_IN1, LOW);
    //led long
    digitalWrite(7, LOW);
    //led short
    for(int i=0;i<4;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    pixels.show(); 
    delay(500); 
    }
   }
   photocellReading=1023-photocellReading;
   delay(100);
 }

