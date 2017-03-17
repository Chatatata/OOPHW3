/*
 * @Author
 * Student Name: Buğra Ekuklu
 * Student ID : 150120016
 * Date: May 5th, 2016
 */

#ifndef BookDeclaration
#define BookDeclaration

#include <iostream>
#include "sizedobject.h"

class Book : public SizedObject {
public:
    Book(std::string name = "", float weight = 0.00f, float length = 0.00f, float width = 0.00f) : SizedObject(weight, length, width), name(name)
    {
        //  Empty implementation
    }
    
    std::string name;
    
#if __cplusplus <= 199711L
    float currentWeight() const {
#else
    float currentWeight() const override {
#endif
        return weight;
    }
    
    friend std::ostream &operator<<(std::ostream &stream, Book &book);
};

std::ostream &operator<<(std::ostream &stream, Book &book) {
    stream << "Book Label: " << book.name << " # " << book.length << "x" << book.width << " " << book.currentWeight() << "kg";
    
    return stream;
}

#endif /* BookDeclaration */
