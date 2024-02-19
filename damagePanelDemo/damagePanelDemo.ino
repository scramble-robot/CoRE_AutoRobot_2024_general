#include <Adafruit_NeoPixel.h>

#define LED_PIN 2
#define SW_PIN 3
#define NUMPIXELS 24
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

/*------Set LED color------*/
uint32_t LEDColor= pixels.Color(255, 0, 0); //Red
//uint32_t LEDColor= pixels.Color(0, 0, 255); //Blue
//uint32_t LEDColor= pixels.Color(0, 128, 128); //Yellow

volatile bool Yoroi1HitFlg = false;
uint8_t delayTime;

void hit1(void);

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW_PIN), hit1, RISING);
  pixels.begin();
}

void loop() {
  if(Yoroi1HitFlg==false){
    for(uint8_t i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, LEDColor);
    }
    delayTime=100;
  }
  else{
    for(uint8_t i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    delayTime=300;
    Yoroi1HitFlg = false;
  }
  pixels.show();
  delay(delayTime);
}

void hit1(void) {
  Yoroi1HitFlg = true;
}
