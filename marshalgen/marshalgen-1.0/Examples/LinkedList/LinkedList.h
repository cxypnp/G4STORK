#include <stdio.h>
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

//MSH_BEGIN
class LinkedList{
public:
  int head;        //MSH: primitive
  LinkedList *next; //MSH: predefined_ptr
public:
  LinkedList(int = 0, LinkedList* = NULL);
};
//MSH_END

#endif
