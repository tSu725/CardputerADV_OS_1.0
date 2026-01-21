#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <functional>
#include "Item/Item.h"

class Menu {
public:
    int curr = 0;
    int window_top = 0;
    std::vector<Item*> items;

    Menu* prev = nullptr;
    int prev_curr = -1;

    void addItem(Item* item);
    void addItem(const std::string& name, std::function<void()> cb = nullptr);

    void up();
    void down();
    void select();
};

#endif
