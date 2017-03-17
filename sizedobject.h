/*
 * @Author
 * Student Name: Buğra Ekuklu
 * Student ID : 150120016
 * Date: May 5th, 2016
 */

#ifndef SizedObject_h
#define SizedObject_h

class SizedObject {
public:
    float weight;
    float length;
    float width;
    
    SizedObject(float weight = 0.00f, float length = 0.00f, float width = 0.00f) : weight(weight), length(length), width(width)
    {
        //  Empty implementation
    }
    
    virtual ~SizedObject() {
        //  Empty implementation
    }
    
    virtual float currentWeight() const = 0;
};

#endif /* SizedObject_h */
