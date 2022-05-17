#include <Arduino.h>
#include "AdvancedSevenSegment.h"

AdvanceSevenSegment::AdvanceSevenSegment(bool type, int a, int b, int c, int d, int e, int f, int g, int dot) {
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
    _f = f;
    _g = g;
    _dot = dot;
    this->type = type;
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dot, OUTPUT);

}

void AdvanceSevenSegment::setNumber(int number) {
    switch (number) {
    case 0:
        this->print(1, 1, 1, 1, 1, 1, 0);
        break;
    case 1:
        this->print(0, 1, 1, 0, 0, 0, 0);
        break;
    case 2:
        this->print(1, 1, 0, 1, 1, 0, 1);
        break;
    case 3:
        this->print(1, 1, 1, 1, 0, 0, 1);
        break;
    case 4:
        this->print(0, 1, 1, 0, 0, 1, 1);
        break;
    case 5:
        this->print(1, 0, 1, 1, 0, 1, 1);
        break;
    case 6:
        this->print(1, 0, 1, 1, 1, 1, 1);
        break;
    case 7:
        this->print(1, 1, 1, 0, 0, 0, 0);
        break;
    case 8:
        this->print(1, 1, 1, 1, 1, 1, 1);
        break;
    case 9:
        this->print(1, 1, 1, 1, 0, 1, 1);
        break;

        // for unknown number display dash
    default:
        setDash();

    }

}

void AdvanceSevenSegment::setCharacter(char c) {
    //support UpperCase chars
    c = tolower(c);

    switch (c) {
    case 'a':
        this->print(1, 1, 1, 0, 1, 1, 1);
        break;
    case 'b':
        this->print(0, 0, 1, 1, 1, 1, 1);
        break;
    case 'c':
        this->print(1, 0, 0, 1, 1, 1, 0);
        break;
    case 'd':
        this->print(0, 1, 1, 1, 1, 0, 1);
        break;
    case 'e':
        this->print(1, 0, 0, 1, 1, 1, 1);
        break;
    case 'f':
        this->print(1, 0, 0, 0, 1, 1, 1);
        break;
    case 'h':
        this->print(0, 1, 1, 0, 1, 1, 1);
        break;
    case 'l':
        this->print(0, 0, 0, 1, 1, 1, 0);
        break;
    case 'p':
        this->print(1, 1, 0, 0, 1, 1, 1);
        break;
    case 'q':
        this->print(1, 1, 1, 0, 0, 1, 1);
        break;
    case 'u':
        this->print(0, 1, 1, 1, 1, 1, 0);
        break;
    case 'y':
        this->print(0, 1, 1, 1, 0, 1, 1);
        break;

        // for unknown character print dash
    default:
        this->setDash();
    }

}

void AdvanceSevenSegment::print(int a, int b, int c, int d, int e, int f, int g) {
    if (this->type) {
        digitalWrite(_a, a);
        digitalWrite(_b, b);
        digitalWrite(_c, c);
        digitalWrite(_d, d);
        digitalWrite(_e, e);
        digitalWrite(_f, f);
        digitalWrite(_g, g);
    }
    else {
        digitalWrite(_a, !a);
        digitalWrite(_b, !b);
        digitalWrite(_c, !c);
        digitalWrite(_d, !d);
        digitalWrite(_e, !e);
        digitalWrite(_f, !f);
        digitalWrite(_g, !g);
    }

}

void AdvanceSevenSegment::setDot(int state) {
    if (this->type) {
        this->digitalWrite(_dot, state);
    }
    else {
        this->digitalWrite(_dot, !state);
    }
}

void AdvanceSevenSegment::setDash() {
    print(0, 0, 0, 0, 0, 0, 1);
}

void AdvanceSevenSegment::refresh(int ms) {
    this->clean();
    this->setDot(1);
    delay(ms);
    this->clean();
    delay(50);
}

void AdvanceSevenSegment::clean() {
    this->setDot(0);
    this->print(0, 0, 0, 0, 0, 0, 0);
}
