#include "Menu.h"

void Menu::addItem(Item* item) {
    items.push_back(item);
}

void Menu::addItem(const std::string& name, std::function<void()> cb) {
    items.push_back(new Item(name, cb));
}

void Menu::up() {
    if (items.empty()) return;
    prev_curr = curr;
    curr = (curr == 0) ? items.size() - 1 : curr - 1;
}

void Menu::down() {
    if (items.empty()) return;
    prev_curr = curr;
    curr = (curr == items.size() - 1) ? 0 : curr + 1;
}

void Menu::select() {
    if (!items.empty() && items[curr])
        items[curr]->run();
}
