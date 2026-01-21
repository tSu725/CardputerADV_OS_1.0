#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <functional>

class Item {
    std::string name;
    std::function<void()> callback;

public:
    Item(const std::string& n, std::function<void()> cb = nullptr);
    void run();
    const std::string& getName() const;
    void setCallback(std::function<void()> fn);
};

#endif
