#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

int rows = 2;
int cols = 16;
int RS = 3;
int ENABLE = 4;
int PINS[] = {5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
    lcd.begin(cols, rows);

    clear();
    delay(100);
    
    writeText("Hello, World!");
}

void pulseEnable() {
    digitalWrite(ENABLE, LOW);
    delayMicroseconds(1);
    digitalWrite(ENABLE, HIGH);
    delayMicroseconds(1);
    digitalWrite(ENABLE, LOW);
    delayMicroseconds(100);
}

void writeText(char *c) {
    while (*c != 0) {
        write(*c);
        c++;
    }
}

void clear() {
    command(0x01);
}

void moveCursorLeft() {
    command(0x10);
}

void moveCursorRight() {
    command(0x14);
}

void moveScreenLeft() {
    command(0x18);
}

void moveScreenRight() {
    command(0x1C);
}

void displayOn() {
    command(0x0E);
}

void displayOff() {
    command(0x08);
}

void command(uint8_t value) {
    send(value, 0);
}

void write(uint8_t value) {
    send(value, 1);
}

void send(uint8_t bits, uint8_t mode) {
    digitalWrite(RS, mode);

    for (int i = 0; i < 8; i++) {
        digitalWrite(PINS[i], (bits >> i) & 0x01);
    }

    pulseEnable();
}

void loop() {
    
}