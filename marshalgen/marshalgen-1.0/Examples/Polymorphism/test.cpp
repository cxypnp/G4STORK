#include <iostream>
#include <string>
//using namespace std;

#include "Animal.h"
#include "Cat.h"
#include "MarshaledAnimal.h"
#include "MarshaledCat.h"

int main(int argc,char** argv){
  // Create objects
  Animal *c = new Cat(10.0);
  Animal *d = new Dog(20.0);
  
  Cage* catcage = new Cage(1, c);
  Cage* dogcage = new Cage(2, d);

  // marshaling objects "catcage" and "dogcage"
  MarshaledCage mc(catcage);
  MarshaledCage md(dogcage);

  char* catcage_buf = mc.getBuffer();
  int catcage_bufsize = mc.getBufferSize();
  char* dogcage_buf = md.getBuffer();
  int dogcage_bufsize = md.getBufferSize();

  //delete catcage;  // will automatically delete c
  //delete dogcage;  // will automatically delete d

  // assume the buffers are sent over the network
  // we now re-construct the objects at the other side
  MarshaledCage m1(catcage_buf);
  MarshaledCage m2(dogcage_buf);

  Cage* c1 = m1.unmarshal();
  Cage* c2 = m2.unmarshal();

  std::cout << "Cat cage size=" << c1->size <<"; type=" << (c1->an->type.buffer()) << std::endl;
  std::cout << "Dog cage size=" << c2->size <<"; type=" << (c2->an->type.buffer()) << std::endl;

  delete(c1);
  delete(c2);
}
