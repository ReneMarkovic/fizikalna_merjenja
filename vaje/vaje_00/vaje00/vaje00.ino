#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;
Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

struct RGB {
    uint8_t r, g, b;
};


constexpr RGB COLOR_OFF   = {0, 0, 0};
constexpr RGB COLOR_RED   = {255, 0, 0};
constexpr RGB COLOR_YELLOW   = {180, 180, 0};
constexpr RGB COLOR_WHITE   = {255, 255, 255};
// ...Feel free to add more colors here...
constexpr RGB CUSTOM_COLOR = {255, 0, 255}; 

void setColor(const RGB& color, uint8_t brightness = 100) {
    uint16_t scale = (uint16_t)brightness * 255 / 100;
    uint8_t r = (uint8_t)(((uint16_t)color.r * scale) / 255);
    uint8_t g = (uint8_t)(((uint16_t)color.g * scale) / 255);
    uint8_t b = (uint8_t)(((uint16_t)color.b * scale) / 255);
    rgbLed.setPixelColor(0, rgbLed.Color(r, g, b));
    rgbLed.show();
}


void setup() {
  Serial.begin(115200);
  rgbLed.begin(); 
  rgbLed.show(); 
}

void loop() {
    setColor(COLOR_WHITE, 100); // 50% brightness
    delay(1000);
    setColor(COLOR_OFF);
    delay(1000);
}
