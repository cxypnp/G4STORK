#include "LinkedList.h"
#include "MarshaledLinkedList.h"

LinkedList::LinkedList(int size, LinkedList* root){
  head = size;
  next = root;
}

int main(int argc,char** argv){
  LinkedList* lst = new LinkedList(1,NULL);
  // marshaling object "lst"
  MarshaledLinkedList m(lst);

  // m.getBuffer() returns the marshaled  buffer of "lst"
  char* marshalBuffer = m.getBuffer();

  // now we unmarshal (reconstruct a LinkedList object from the buffer)
  MarshaledLinkedList m2(marshalBuffer);
  LinkedList* lst2 = m2.unmarshal();

  delete(lst);
  delete(lst2);
}
