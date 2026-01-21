#ifndef RENDER_H
#define RENDER_H
#include <M5Cardputer.h>
#include <vector>
#include "Menu/Menu.h"


extern LGFX_Sprite sprite;

class Render {
public:
    void begin();
    void render(Menu& menu);
private:
    const int window_size = 4;
    const int item_h = 25;
    int scroll_offset = 0;
    const int scroll_speed = 3;
    void updateScroll(Menu& menu);
};
#endif
