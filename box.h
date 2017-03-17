/*
 * @Author
 * Student Name: Buğra Ekuklu
 * Student ID : 150120016
 * Date: May 5th, 2016
 */

#ifndef BoxDeclaration
#define BoxDeclaration

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include "sizedobject.h"

template <typename T>
class Box : public SizedObject {
private:
#if __cplusplus <= 199711L
#warning Please compile with '-std=gnu++11' (aka GNU C++11 standard) option, at least.
    T *objects = NULL;
#else
    T *objects = nullptr;
#endif
    unsigned int count;
    unsigned int capacity;
    
    float maximumAllowedWeight;
    
    void checkArithmeticBounds(const T& object) const;
public:
    //  RAII: Rule of three
    Box(float weight = 0.00f, float length = 0.00f, float width = 0.00f, float maximumAllowedWeight = 0.00f);
    ~Box();
    Box(const Box<T> &other);
    
    Box<T> &operator = (const Box<T>& object);
    
    void add(const T &object);
    void add(T *object, unsigned int numberOfItems);
    
    T &operator[](unsigned int index) const;
    
    T &objectAtIndex(unsigned int index) const;
    
#if __cplusplus <= 199711L
    float currentWeight() const;
#else
    float currentWeight() const override;
#endif
    
    friend std::ostream & operator<<(std::ostream &stream, Box<T> &object) {
        
        stream << "***** " << abi::__cxa_demangle(typeid(object).name(), NULL, NULL, NULL) << " *****" << std::endl;
        stream << "Box item count: " << object.count << std::endl;
        stream << "Size: " << object.length << "x" << object.width << " Box Weight: " << object.weight << "kg Total/Maximum Allowed Weight: " << object.currentWeight() << "kg/" << object.maximumAllowedWeight << "kg" << std::endl;
        stream << "Items:" << std::endl;
        
        for (unsigned int i = 0; i < object.count; ++i) {
            stream << i + 1 << ":" << object.objects[i] << std::endl;
        }
        
        stream << "********************" << std::endl;
        
        return stream;
    }
};

#endif /* BoxDeclaration */
