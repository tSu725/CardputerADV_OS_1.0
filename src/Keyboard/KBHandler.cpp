#include "KBHandler.h"

void KBHandler::handle(Menu*& menu) {
    M5Cardputer.update();
    if (!M5Cardputer.Keyboard.isChange()) return;

    auto st = M5Cardputer.Keyboard.keysState();

    if (st.enter)
        menu->select();

    for (char c : st.word) {
        if (c == '`' && menu->prev) {
            menu->curr = 0;
            menu->window_top = 0;
            menu = menu->prev;
        }
        if (c == ';') menu->up();
        if (c == '.') menu->down();
    }
}
