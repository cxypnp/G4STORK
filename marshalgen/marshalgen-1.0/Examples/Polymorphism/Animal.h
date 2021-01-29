#ifndef __ANIMAL_H
#define __ANIMAL_H

#include "MyString.h"

// MSH_BEGIN
class Animal {
public:
   /* if "type" is "cat" then the object is of type Cat,
     "type" is "dog" then the object is of type Dog. */
    MyString type;  /* MSH: predefined */

    /* MSH_derivedclass:
      ($THIS->type.equals("cat")) => Cat(0)
      | ($THIS->type.equals("dog")) => Dog(0)
     */
};
//MSH_END

//MSH_include_begin
#include "MarshaledMyString.h"
#include "MarshaledCat.h"
//MSH_include_end

//MSH_BEGIN
class Cage {
public:
    int size;   //MSH: primitive
    Animal* an;  //MSH: predefined_ptr

    Cage() {
	size = 0;
	an = NULL;
    }
    Cage(int s, Animal* a){
	size = s;
        an = a;
    } 
    ~Cage(){
	delete an;
    }
};
//MSH_END

#endif
