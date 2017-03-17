/*
 * @Author
 * Student Name: Buğra Ekuklu
 * Student ID : 150120016
 * Date: May 5th, 2016
 */

#ifndef ToyDeclaration
#define ToyDeclaration

#include <iostream>
#include "sizedobject.h"

class Toy : public SizedObject {
public:
    std::string name;
    bool containsBattery;
    
    Toy(std::string name = "", float weight = 0.00f, float length = 0.00f, float width = 0.00f, bool containsBattery = false) : SizedObject(weight, length, width), name(name), containsBattery(containsBattery)
    {
        //  Empty implementation
    }
    
    void setContainsBattery(bool value) {
        containsBattery = value;
    }
    
#if __cplusplus <= 199711L
    float currentWeight() const {
#else
    float currentWeight() const override {
#endif
        return weight;
    }
    
    friend std::ostream &operator<<(std::ostream &stream, Toy &toy);
};

std::ostream &operator<<(std::ostream &stream, Toy &toy) {
    stream << "Toy Label: " << toy.name << " # " << toy.length << "x" << toy.width << " " << toy.currentWeight() << "kg " << (toy.containsBattery ? "Contains":"No") << " Battery";
    
    return stream;
}

#endif /* ToyDeclaration */
