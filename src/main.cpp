#include "App/App.h"
App app;

void setup() {
app.setup();
}

void loop() {
app.loop();
}


// #include <USB.h>
// #include <USBHIDMouse.h>
// #include <M5Cardputer.h>

// USBHIDMouse Mouse;

// void setup() {
//     USB.begin();
//     Mouse.begin();
// }

// void loop() {
//     Mouse.move(5, 0);  // движение курсора вправо
//     delay(50);
// }


// #include <SPI.h>
// #include <M5Cardputer.h>

// #define NRF_CS  10

// byte nrf_readReg(byte addr) {
//     digitalWrite(NRF_CS, LOW);
//     SPI.transfer(addr & 0x1F);
//     byte val = SPI.transfer(0);
//     digitalWrite(NRF_CS, HIGH);
//     return val;
// }

// void setup() {
//     auto cfg = M5.config();
//     M5Cardputer.begin(cfg);
//     M5Cardputer.Display.setRotation(1);

//     SPI.begin();
//     pinMode(NRF_CS, OUTPUT);
//     digitalWrite(NRF_CS, HIGH);

//     delay(200);

//     M5Cardputer.Display.fillScreen(BLACK);
//     M5Cardputer.Display.setTextSize(2);
//     M5Cardputer.Display.setCursor(10, 10);
//     M5Cardputer.Display.setTextColor(WHITE);

//     M5Cardputer.Display.println("NRF24 check...");

//     delay(300);

//     byte status = nrf_readReg(0x07);

//     M5Cardputer.Display.setCursor(10, 60);

//     if (status == 0x00 || status == 0xFF) {
//         M5Cardputer.Display.setTextColor(RED);
//         M5Cardputer.Display.println("NRF24 NOT FOUND!");
//     } else {
//         M5Cardputer.Display.setTextColor(GREEN);
//         M5Cardputer.Display.println("NRF24 OK!");
//     }
// }

// void loop() {
// }






