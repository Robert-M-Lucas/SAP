#ifndef ARDUINO_FLASHER_CODE_H
#define ARDUINO_FLASHER_CODE_H

#include <Arduino.h>

constexpr byte LDA = 0b00000000;
constexpr byte ADD = 0b00010000;
constexpr byte SUB = 0b00100000;
constexpr byte OUT = 0b11100000;
constexpr byte HLT = 0b11110000;
constexpr byte XX = 0b010101111;

byte code[16] = {
    LDA + 9,
    ADD + 10,
    ADD + 11,
    SUB + 12,
    OUT,
    HLT,
    XX,
    XX,
    XX,
    1,
    2,
    3,
    4,
    XX,
    XX,
    XX
};

#endif //ARDUINO_FLASHER_CODE_H
