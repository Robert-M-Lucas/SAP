#include <Arduino.h>

#include "code.h"
#include "constants.h"

void setup() {
    Serial.begin(9600);
    pinMode(WRITE_BUTTON, INPUT_PULLUP);
    for (pin p : ADDRESS_PINS) { pinMode(p, OUTPUT); }
    for (pin p : DATA_PINS) { pinMode(p, OUTPUT); }
}

void loop() {
    Serial.println("Ready");
    while (digitalRead(WRITE_BUTTON)) {}

    Serial.println("Writing data");

    digitalWrite(RAM_WRITE_ENABLE_PIN, LOW);
    delay(RAM_UPDATE_INTERVAL);

    for (uint8_t addr = 0; addr < RAM_SIZE; addr++) {
        for (uint8_t i = 0; i < 4; i++) {
            digitalWrite(ADDRESS_PINS[i], ((1 << i) & addr) != 0 ? HIGH : LOW);
        }

        for (uint8_t i = 0; i < 8; i++) {
            digitalWrite(DATA_PINS[i], ((1 << i) & code[addr]) != 0 ? HIGH : LOW);
        }

        delay(RAM_UPDATE_INTERVAL);
        digitalWrite(RAM_WRITE_ENABLE_PIN, HIGH);
        delay(RAM_UPDATE_INTERVAL);
        digitalWrite(RAM_WRITE_ENABLE_PIN, LOW);
        delay(RAM_UPDATE_INTERVAL);
    }

    Serial.println("Done");
}