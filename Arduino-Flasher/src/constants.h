//
// Created by robertlucas on 28/12/23.
//

#ifndef ARDUINO_FLASHER_CONSTANTS_H
#define ARDUINO_FLASHER_CONSTANTS_H

#include "Arduino.h"

typedef uint8_t pin;

constexpr unsigned long RAM_UPDATE_INTERVAL = 10;

constexpr pin WRITE_BUTTON = 3;

constexpr pin RAM_WRITE_ENABLE_PIN = 4;

constexpr pin ADDRESS_PINS[4] = {A0, A1, A2, A4};

constexpr pin DATA_PINS[8] = {5, 6, 7, 8, 9, 10, 11, 12};

constexpr uint8_t RAM_SIZE = 16;

#endif //ARDUINO_FLASHER_CONSTANTS_H
