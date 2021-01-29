#ifndef __CAT_H
#define __CAT_H

//MSH_include_begin
#include "MarshaledMyString.h"
//MSH_include_end
#include "MyString.h"

//MSH_BEGIN
class Cat : public Animal{
    //MSH_constructor: Cat(0)
public:
    float sleep_time;   //MSH: primitive
   Cat(){}				   
   Cat(float t) { 
	type = *(new MyString("cat"));
	sleep_time = t;
   }
};
//MSH_END

//MSH_BEGIN
class Dog : public Animal{
    /* MSH_constructor: Dog(0) */
public:
    double weight;   //MSH: primitive
   Dog(){}				   
   Dog(double t) { 
	type = *(new MyString("dog"));
	weight = t;
   }
};
//MSH_END


#endif
