#include "mocha.h"

#include <iostream>

#include "ingredient.h"
#include "sub_ingredients.h"

Mocha::Mocha() : EspressoBased("Mocha") {
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
}
Mocha::Mocha(const Mocha& mocha) : EspressoBased(mocha) {
    for (auto& i : mocha.side_items) {
        side_items.push_back(i->clone());
    }
}

Mocha& Mocha::operator=(const Mocha& mocha) {
    if (&mocha != this) {
        for (const auto& i : side_items) {
            delete i;
        }
        for (const auto& i : ingredients) {
            delete i;
        }
        ingredients.clear(), side_items.clear();
        for (auto& i : mocha.ingredients) {
            ingredients.push_back(i->clone());
        }
        for (auto& i : mocha.side_items) {
            side_items.push_back(i->clone());
        }
    }
    return *this;
}

Mocha::~Mocha() {
    for (auto& i : side_items) {
        delete i;
    }
    side_items.clear();
}

double Mocha::price() {
    double p = 0;
    for (auto& i : ingredients) {
        p += i->price();
    }
    for (auto& i : side_items) {
        p += i->price();
    }
    return p;
}

void Mocha::brew() {  // a naive implement
    std::cout << "making mocha..." << std::endl;
    for (const auto& i : ingredients) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    for (const auto& i : side_items) {
        std::cout << "adding " << i->get_name() << "..." << std::endl;
    }
    std::cout << "mocha finished" << std::endl;
}

void Mocha::add_side_item(Ingredient* side) { side_items.push_back(side); }