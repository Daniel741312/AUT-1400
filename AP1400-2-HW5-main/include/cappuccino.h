#ifndef CAPPUCCINO
#define CAPPUCCINO
#include <string>
#include <vector>

#include "espresso_based.h"
#include "ingredient.h"

class Cappuccino : public EspressoBased {
   public:
    Cappuccino();
    Cappuccino(const Cappuccino& cap);
    ~Cappuccino() override;
    Cappuccino& operator=(const Cappuccino& cap);

    double price() override;
    void brew() override;

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items() { return side_items; };

   private:
    std::vector<Ingredient*> side_items;
};
#endif  // CAPPUCCINO