/*
 * @Author
 * Student Name: Buğra Ekuklu
 * Student ID : 150120016
 * Date: May 5th, 2016
 */

#include "box.h"

template <typename T>
Box<T>::Box(float weight, float length, float width, float maximumAllowedWeight)
: SizedObject(weight, length, width), count(0), capacity(5), maximumAllowedWeight(maximumAllowedWeight)
{
    objects = new T[capacity]();
}

template <typename T>
Box<T>::~Box()
{
    delete [] objects;
}

template <typename T>
Box<T>::Box(const Box<T> &other)
: SizedObject(other.weight, other.length, other.width), objects(new T[other.capacity]), count(other.count), capacity(other.capacity), maximumAllowedWeight(other.maximumAllowedWeight)
{
    //  RAII copy constructor /w strong exception-guarantee
    for (unsigned int i = 0; i < count; i++) {
        // Now you can use placement new to copy the elements from
        // source into the current vector.
        objects[i] = T(other.objects[i]);
    }
}

template <typename T>
Box<T> &
Box<T>::operator = (const Box<T>& other)
{
    delete [] objects;
    
    weight = other.weight;
    length = other.length;
    width = other.width;
    maximumAllowedWeight = other.maximumAllowedWeight;
    count = other.count;
    objects = new T[other.capacity]();
    
    for (unsigned int i = 0; i < count; i++) {
        // Now you can use placement new to copy the elements from
        // source into the current vector.
        objects[i] = T(other.objects[i]);
    }
    
    return *this;
}

template <typename T>
void
Box<T>::add(const T &object)
{
    //  Check arithmetic possibilities first
    checkArithmeticBounds(object);
    
    //  Check if container is full
    if (capacity == count) {
        //  Double capacity first
        capacity *= 2;
        
        //  Allocate a new buffer
        T *buffer = new T[capacity]();
        
        //  Copy elements to the newly allocated buffer
        for (unsigned int i = 0; i < count; ++i) {
            buffer[i] = T(objects[i]);
        }
        
        //  Release member buffer
        delete [] objects;
        
        //  Assign new buffer as member
        objects = buffer;
    }
    
    //  Append the object
    objects[count++] = T((T)object);
}

template <typename T>
void
Box<T>::add(T *object, unsigned int numberOfItems)
{
    //  Map each element in wild pointer to add method
    for (unsigned int i = 0; i < numberOfItems; ++i) {
        add(object[i]);
    }
}

template <typename T>
T &
Box<T>::operator [] (unsigned int index) const
{
    return objectAtIndex(index);
}

template <typename T>
T &
Box<T>::objectAtIndex(unsigned int index) const
{
    if (index < count) {
        return objects[index];
    } else {
        throw std::string("Index out of bounds!");
    }
}

template <typename T>
void
Box<T>::checkArithmeticBounds(const T& object) const
{
    float totalWeight = object.currentWeight() + currentWeight();
    
    if (!((object.width <= length && object.length <= width) || (object.length <= width && object.width <= length))) {
        throw std::string("The dimensions of the contained object should be equal or smaller than those of the box!");
    } else if (totalWeight > maximumAllowedWeight) {
        throw std::string("The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!");
    }
}

template <typename T>
float
Box<T>::currentWeight() const
{
    float result = weight;
    
    for (unsigned int i = 0; i < count; ++i) {
        result += objects[i].currentWeight();
    }
    
    return result;
}

