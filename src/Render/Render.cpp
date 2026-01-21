#include "Render.h"

#define WIDTH 240
#define HEIGHT 135

LGFX_Sprite sprite(&M5Cardputer.Display);

void Render::begin() {
    sprite.createSprite(WIDTH, HEIGHT);
    sprite.setFont(&fonts::Font4);
}

void Render::updateScroll(Menu& menu) {
    bool jumpFromLastToFirst = (menu.prev_curr == menu.items.size() - 1 && menu.curr == 0);
    bool jumpFromFirstToLast = (menu.prev_curr == 0 && menu.curr == menu.items.size() - 1);
    if (menu.curr >= menu.window_top + window_size) {
        int speed = jumpFromFirstToLast ? 10 : scroll_speed;
        scroll_offset += speed;
        if (scroll_offset >= item_h) {
            scroll_offset -= item_h;
            menu.window_top += 1;
        }
    }
    if (menu.curr < menu.window_top) {
        int speed = jumpFromLastToFirst ? 10 : scroll_speed;
        scroll_offset -= speed;
        if (scroll_offset <= -item_h) {
            scroll_offset += item_h;
            menu.window_top -= 1;
        }
    }
}

void Render::render(Menu& menu) {
    updateScroll(menu);
    sprite.fillSprite(TFT_BLACK);
    int base_y = 20;
    for (int i = 0; i < window_size; i++) {
        int idx = menu.window_top + i;
        if (idx >= menu.items.size()) break;
        const std::string& txt = menu.items[idx]->getName();
        int y = base_y + i * item_h - scroll_offset;
        int x = 40;
        if (y < -item_h || y > HEIGHT) continue;
        if (idx == menu.curr) {
            sprite.setTextColor(TFT_GREEN);
            sprite.drawString(">", x - 20, y);
        } else {
            sprite.setTextColor(TFT_WHITE);
            sprite.setFont(&fonts::Font4);
        }
        sprite.drawString(txt.c_str(), x, y);
    }
    sprite.pushSprite(0, 0);
}
