#include <Arduino.h>

constexpr int IZHOD_GPIO = 3;
constexpr int ADC_GPIO = 2;
constexpr unsigned int preklop_ms = 3000;
constexpr unsigned float R = 10000.0;

unsigned int zadnjiPreklop = 0;
unsigned int zadnjiVzorec = 0;
bool izhodVisok = false;

void setup() {
  Serial.begin(115200);
  Serial.print("Setup ... ");
  pinMode(IZHOD_GPIO, OUTPUT);
  digitalWrite(IZHOD_GPIO, LOW);
  analogReadResolution(12);
  analogSetPinAttenuation(ADC_GPIO, ADC_11db);

  zadnjiPreklop = millis();
  zadnjiVzorec = zadnjiPreklop;
}

void loop() {
  const unsigned int zdaj = millis();
  if(zdaj - zadnjiPreklop >= preklop_ms){
    zadnjiPreklop = zdaj;
    izhodVisok = !izhodVisok;
    digitalWrite(IZHOD_GPIO, izhodVisok ? HIGH:LOW);
  }

  const uint32_t napetost_mv = analogReadMilliVolts(ADC_GPIO);
  const float I = napetost_mv/R;
  Serial.print("Tok = ");
  Serial.print(I);
  Serial.print(", Napetost = ");
  Serial.print(napetost_mv);
  Serial.println();
}