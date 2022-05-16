//
// Created by ionic on 2022/5/16.
//

#ifndef LEARNOPENCV_SHOPPINGCART_H
#define LEARNOPENCV_SHOPPINGCART_H
#include "header.h"
class ShoppingCart {
private:
    vector<string> *items_;

public:
    ShoppingCart() :
            items_(new vector<string>()) {
    }

    ~ShoppingCart() {
        // Need to free up items here
        cout << "Destroying ..." << endl;
        delete items_;
    }

    void addItem(const string &item) {
        items_->push_back(item);
    }
};


#endif //LEARNOPENCV_SHOPPINGCART_H
