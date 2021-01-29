
#ifndef _FOO_H
#define _FOO_H

//MSH_include_begin
#include "MarshaledBar.h"
//MSH_include_end

//MSH_BEGIN
class Foo {
public:
    int x;    //MSH: primitive
    float z;    //MSH: transient
    char dummy;	 
    Bar bar;  //MSH: predefined
    Bar* ptr; // MSH: ptr_shallow_copy
};
//MSH_END
#endif
