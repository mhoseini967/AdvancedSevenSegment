#include <Arduino.h>
#include <AdvancedSevenSegment.h>

AdvanceSevenSegment sevenSegment(31, 33, 35, 37, 39, 41, 43, 45);

void setup() {
}

void loop() {

    for (int i = 0; i <= 9; ++i) {
        sevenSegment.setNumber(i);
        delay(1000);
    }
    sevenSegment.refresh();

    char list[] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'l', 'p', 'q', 'u', 'y'};
    for (char c : list) {
        sevenSegment.setCharacter(c);
        delay(1000);
    }
    sevenSegment.refresh();

}
