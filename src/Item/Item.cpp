#include "Item.h"

Item::Item(const std::string& n, std::function<void()> cb)
    : name(n), callback(cb) {}

void Item::run() {
    if (callback) callback();
}

const std::string& Item::getName() const {
    return name;
}

void Item::setCallback(std::function<void()> fn) {
    callback = fn;
}
