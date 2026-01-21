#ifndef APP_H
#define APP_H

#include "Menu/Menu.h"
#include "Render/Render.h"
#include "Keyboard/KBHandler.h"

class App {
public:
    void setup();
    void loop();

private:
    void setupMenus();
    Menu mainMenu;
    Menu settingsMenu;

    Menu* currentMenu = &mainMenu;
    Render renderer;
    KBHandler kb;
};

#endif
