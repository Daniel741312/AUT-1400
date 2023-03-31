#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include "ingredient.h"

#define DEFCLASS(class_name, price_unit)                                       \
    class class_name : public Ingredient {                                     \
       public:                                                                 \
        class_name(size_t units) : Ingredient{price_unit, units} {             \
            this->name = #class_name;                                          \
        }                                                                      \
        virtual double price() override { return units * price_unit; };        \
        virtual Ingredient* clone() override { return new class_name(*this); } \
    }

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);

#endif