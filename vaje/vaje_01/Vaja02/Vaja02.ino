#include <Arduino.h>

enum class Naloga { Delilnik, Tok, RC };

// Izberite nalogo, ki ustreza priključenemu vezju.
constexpr Naloga NALOGA = Naloga::Delilnik;
constexpr int IZHOD_GPIO = 3;
constexpr int ADC_GPIO = 2;
constexpr unsigned long PREKLOP_MS = NALOGA == Naloga::RC ? 5000 : 3000;
constexpr unsigned long VZOREC_MS = 50;
constexpr float MERILNI_UPOR_OHM = 220.0f;

unsigned long zadnjiPreklop = 0;
unsigned long zadnjiVzorec = 0;
bool izhodVisok = false;

void setup() {
  Serial.begin(115200);
  pinMode(IZHOD_GPIO, OUTPUT);
  digitalWrite(IZHOD_GPIO, LOW);
  analogReadResolution(12);
  analogSetPinAttenuation(ADC_GPIO, ADC_11db);

  zadnjiPreklop = millis();
  zadnjiVzorec = zadnjiPreklop;
}

void loop() {
  const unsigned long zdaj = millis();

  if (zdaj - zadnjiPreklop >= PREKLOP_MS) {
    zadnjiPreklop = zdaj;
    izhodVisok = !izhodVisok;
    digitalWrite(IZHOD_GPIO, izhodVisok ? HIGH : LOW);
  }

  if (zdaj - zadnjiVzorec < VZOREC_MS) {
    return;
  }
  zadnjiVzorec = zdaj;
  const uint32_t napetost_mV = analogReadMilliVolts(ADC_GPIO);

  if (NALOGA == Naloga::Tok) {
    const float tok_mA = napetost_mV / MERILNI_UPOR_OHM;
    Serial.print("Tok_mA:");
    Serial.println(tok_mA, 3);
  } else {
    // Uin_mV je nazivna referenca glede na stanje digitalnega izhoda.
    Serial.print("Uin_mV:");
    Serial.print(izhodVisok ? 3300 : 0);
    Serial.print('\t');
    Serial.print("Umer_mV:");
    Serial.println(napetost_mV);
  }
}
