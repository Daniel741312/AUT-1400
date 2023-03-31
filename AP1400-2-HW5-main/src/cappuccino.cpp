#include "cappuccino.h"

#include <iostream>

#include "ingredient.h"
#include "sub_ingredients.h"

Cappuccino::Cappuccino() : EspressoBased("Cappuccino") {
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
}
Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap) {
    name = cap.name;
    for (const auto& i : cap.side_items) {
        side_items.push_back(i->clone());
    }
}

Cappuccino::~Cappuccino() {
    for (const auto& i : side_items) {
        delete i;
    }
    side_items.clear();
}

Cappuccino& Cappuccino::operator=(const Cappuccino& cap) {
    if (&cap != this) {
        // delete this;
        for (const auto& i : side_items) {
            delete i;
        }
        for (const auto& i : ingredients) {
            delete i;
        }
        ingredients.clear(), side_items.clear();
        for (const auto& i : cap.ingredients) {
            ingredients.push_back(i->clone());
        }
        for (const auto& i : cap.side_items) {
            side_items.push_back(i->clone());
        }
    }
    return *this;
}

double Cappuccino::price() {
    double p = 0;
    for (auto& i : ingredients) {
        p += i->price();
    }
    for (auto& i : side_items) {
        p += i->price();
    }
    return p;
}

void Cappuccino::brew() {
    std::cout << "making cappuccino..." << std::endl;
    for (const auto& i : ingredients) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    for (const auto& i : side_items) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    std::cout << "cappuccino finished" << std::endl;
}

void Cappuccino::add_side_item(Ingredient* side) { side_items.push_back(side); }