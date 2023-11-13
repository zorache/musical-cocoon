#include <Adafruit_NeoPixel.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;




#define PIN_NEO_PIXEL  11  // pin 11 connected to NeoPixel
#define NUM_PIXELS     50  // The number of LEDs (pixels) on NeoPixel

Adafruit_NeoPixel strip(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);


void blue_green_gradient(int all_on);
void all_on(int r,int g,int b, int randomrgb);


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Bluetooth device name
  strip.begin(); 
}

void loop() {
 if (SerialBT.available()) {
        char option = SerialBT.read();
        Serial.println(option);

      switch (option) {
      case 'B':  
        blue_green_gradient(0);
        break;


      case 'A':  
        all_on(100,200,135,0);
        break;
    }
    }

}


void blue_green_gradient(int all_on=0){
  strip.clear();
  for (int i = 0; i < NUM_PIXELS; i++) {
    int greenValue = map(i, 0, NUM_PIXELS / 2, 255, 0);
    int blueValue = map(i, 0, NUM_PIXELS / 2, 0, 255);
    
    strip.setPixelColor(i, strip.Color(0, greenValue, blueValue));
    strip.show();
    delay(500); 
  }
}

void all_on(int r,int g,int b, int randomrgb=0){
  strip.clear();
  if (randomrgb==1){
    int r = random(256);    // Generate a random value between 0 and 255 for red
    int g = random(256);  // Generate a random value between 0 and 255 for green
    int b = random(256);   // Generate a random value between 0 and 255 for blue

  }
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}




