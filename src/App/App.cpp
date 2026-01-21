#include "App/App.h"
#include <M5Cardputer.h>
#include "Settings/Settings.h"

void App::setupMenus() {
    mainMenu.addItem("Settings", [this]() { currentMenu = &settingsMenu; });
    mainMenu.addItem("Wi-Fi");
    mainMenu.addItem("Bluetooth");
    mainMenu.addItem("MP3-player");
    mainMenu.addItem("Option 5");
    mainMenu.addItem("Option 6");
    mainMenu.addItem("Option 7");
    mainMenu.addItem("Option 8");

    settingsMenu.addItem("Sdcard-info", [this]() {Settings::sd_info();});
    settingsMenu.addItem("Display");
    settingsMenu.addItem("Sound");
    settingsMenu.addItem("Back", [this]() { currentMenu = &mainMenu; });
    settingsMenu.prev = &mainMenu;
}

void App::setup() {
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);
    M5Cardputer.Display.setRotation(1);
    setupMenus();
    renderer.begin();
    renderer.render(*currentMenu);
}

void App::loop() {
    kb.handle(currentMenu);
    renderer.render(*currentMenu);
}
