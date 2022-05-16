//
// Created by ionic on 2022/5/16.
//

#ifndef LEARNOPENCV_MAMMAL_H
#define LEARNOPENCV_MAMMAL_H

#include "header.h"

class Mammal {
protected:
    const string name_;
public:
    Mammal() {
        cout << "Mammal()" << endl;
    };

    Mammal(const string &name) : name_(name) {
        cout << "Mammal(const string &name)" << endl;
    };

    virtual void eat() {
        cout << "This Mammal " << name_ << " is eating" << endl;
    }
};

class Tiger : virtual public Mammal {
public:
    Tiger() {
        cout << "Tiger()" << endl;
    };

    void groom();
};

class Lion : virtual public Mammal {
public:
    Lion() {
        cout << "Lion()" << endl;
    };

    void groom();
};

class Liger : public Tiger, public Lion {
public:
    Liger() {
        cout << "Liger()" << endl;
    };

    Liger(const string &name) : Mammal(name) {
        cout << "Liger(const string &name)" << endl;
    };

    void nap();
};

#endif //LEARNOPENCV_MAMMAL_H
