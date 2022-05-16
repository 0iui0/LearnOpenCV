//
// Created by iouoi on 2022/5/16.
//

#include "../include/Mammal.h"
#include "../include/ShoppingCart.h"

int main() {
    Liger Lyle("lyle");
    Lyle.eat();

    {
        ShoppingCart cart;
        cart.addItem("eggs");
        cart.addItem("cheese");
    }
    // When cart goes out of scope here,
    // destructor ShoppingCart::~ShoppingCart() is called automatically

    ShoppingCart *cart = new ShoppingCart();
    cart->addItem("milk");
    cart->addItem("bread");
    delete cart;  // calls destructor ShoppingCart::~ShoppingCart() for cart
}