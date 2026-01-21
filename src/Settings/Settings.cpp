#include "Settings.h"
#include "Render/Render.h"
#include <M5Cardputer.h>
#include <SD.h>
#include <SPI.h>
#include "icons/sd_icon_100x100.h"


using namespace std;
#define SD_SCK   40
#define SD_MISO  39
#define SD_MOSI  14
#define SD_CS    12


String sd_type() { 
    uint8_t type = SD.cardType(); 
    switch (type) { 
        case CARD_MMC: return "MMC"; 
        case CARD_SD: return "SD"; 
        case CARD_SDHC:return "SDHC";
        default: return "Unknown"; 
    } 
}

void Settings::waitExit() {
    while (true) {
        M5Cardputer.update();
        if (M5Cardputer.Keyboard.isKeyPressed('`')) {
            delay(150);
            break;
        }
    }
}

SPIClass spiSD(FSPI);
void Settings::sd_info() {
    sprite.fillSprite(TFT_BLACK);
    spiSD.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
    // Проверяем SD
    if (!SD.begin(SD_CS, spiSD)) {
        sprite.fillSprite(TFT_BLACK);
        sprite.setTextColor(TFT_RED);
        sprite.setTextSize(1);
        std::string text = "SD card missing";
        int textWidth = sprite.textWidth(text.c_str());
        int textHeight = sprite.fontHeight();
        int x = (240 - textWidth) / 2; 
        int y = (135 - textHeight) / 2;  
        sprite.drawString(text.c_str(), x, y);
        sprite.pushSprite(0, 0);
        delay(1000);
    }

    else {
        sprite.drawBitmap(-10, 0, sdcard_icon, 128, 128, TFT_GREEN);
        uint64_t total = SD.totalBytes() / (1024 * 1024);
        uint64_t used  = SD.usedBytes()  / (1024 * 1024);
        uint64_t free  = total - used;
        String type = sd_type();
        String lines[5];
        lines[0] = "Type: " + type;
        lines[1] = "Total: " + String(total) + " MB";
        lines[2] = "Used:  " + String(used) + " MB";
        lines[3] = "Free:  " + String(free) + " MB";
        sprite.setTextColor(TFT_WHITE);
        sprite.setTextSize(1);
        sprite.setFont(&fonts::Font2);
        int fontHeight = sprite.fontHeight();
        int lineSpacing = fontHeight + 5;
        int maxWidth = 0;
        for (int i = 0; i < 5; i++) {
            int width = sprite.textWidth(lines[i].c_str());
            if (width > maxWidth) maxWidth = width;
        }
        int startY = (135 - (5 * lineSpacing - 5)) / 2;
        int textX = 115;
        for (int i = 0; i < 4; i++) {
            sprite.setCursor(textX, startY + i * lineSpacing);
            sprite.print(lines[i]);
        }
        sprite.setTextColor(TFT_YELLOW);
        sprite.setCursor(textX, startY + 4 * lineSpacing);
        sprite.print(lines[4]);
        sprite.pushSprite(0, 0);
        waitExit();
    }
}
