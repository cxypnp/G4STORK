// This file was generated automatically by marshalgen.
// Edit the .msh file and re-run:  marshalgen < XXX.msh


#include "Bar.h"


#ifndef MarshaledBar_H
#define MarshaledBar_H

#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

  class MarshaledBar;

  class ShadowedMarshaledBar : public Bar{
    friend class MarshaledBar;
};

  class MarshaledBar : public MarshaledObj {
public:
    Bar* param;
    ShadowedMarshaledBar* Shadowed_param;
public:


// Function implementations

MarshaledBar(Bar* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledBar*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
    marshal2();
}

MarshaledBar(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledBar() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

Bar* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new Bar();
        this->Shadowed_param = (ShadowedMarshaledBar*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
        return this->param;
    }
}

void unmarshalTo(Bar* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledBar*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
    }
}

void marshal1() {
    //declare field_size to be the size of this field
    int msh_currentSize = 0;
    if (isUnmarshaling())
        throw "Tried to marshal in obj marked isUnmarshaling == true";

    //Copy the sizespec into msh_currentSize here:
    {
      msh_currentSize = sizeof( double );
    }

    //Increase the size of buffer if needed
    msh_size += msh_currentSize + sizeof(int) + sizeof(int); // 4 bytes for the total size of field, 4 bytes for the number of elements in the array
    EXTEND_BUFFER(msh_size);

    //Mark the beginning position for this field, will write the total size of this field here later
    msh_field_begin = msh_cursor;

    //Advance cursor of distance = sizeof(int)
    msh_cursor += sizeof(int);

    //Now just copy "get" functions here
    {
	memcpy(msh_cursor, Shadowed_param->y, sizeof(double ));
    }
    //Now advance the cursor
    msh_cursor += msh_currentSize;
    //Now set the size of this field
    int tmp; //use memcpy instead of *(int*)... =... to prevent bus error
    tmp = (msh_cursor-msh_field_begin) - sizeof(int);
    memcpy(msh_field_begin, &tmp, sizeof(int));

    //Now set msh_size
    msh_size = msh_cursor - msh_buffer;
    tmp = msh_size - sizeof(int);
    memcpy(msh_buffer, &tmp, sizeof(int));

}

void unmarshal1() {
    //declare currentSize to be the size of this field
    int msh_currentSize = 0;
    //copy the size of the current field into currentSize
    memcpy(&msh_currentSize, msh_cursor, sizeof(int));
    msh_cursor += sizeof(int);
    //Now copy the setspec here
    {
	Shadowed_param->y = (double *)malloc(sizeof(double ));
	memcpy(Shadowed_param->y, msh_cursor, sizeof(double ));

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

void marshal2() {
    //declare field_size to be the size of this field
    int msh_currentSize = 0;
    if (isUnmarshaling())
        throw "Tried to marshal in obj marked isUnmarshaling == true";

    //Copy the sizespec into msh_currentSize here:
    {
      MarshaledBar  var(Shadowed_param->b );
      msh_currentSize = var.getBufferSize();
    }

    //Increase the size of buffer if needed
    msh_size += msh_currentSize + sizeof(int) + sizeof(int); // 4 bytes for the total size of field, 4 bytes for the number of elements in the array
    EXTEND_BUFFER(msh_size);

    //Mark the beginning position for this field, will write the total size of this field here later
    msh_field_begin = msh_cursor;

    //Advance cursor of distance = sizeof(int)
    msh_cursor += sizeof(int);

    //Now just copy "get" functions here
    {
	MarshaledBar  var(Shadowed_param->b);
	memcpy(msh_cursor, var.getBuffer(), var.getBufferSize());
    }
    //Now advance the cursor
    msh_cursor += msh_currentSize;
    //Now set the size of this field
    int tmp; //use memcpy instead of *(int*)... =... to prevent bus error
    tmp = (msh_cursor-msh_field_begin) - sizeof(int);
    memcpy(msh_field_begin, &tmp, sizeof(int));

    //Now set msh_size
    msh_size = msh_cursor - msh_buffer;
    tmp = msh_size - sizeof(int);
    memcpy(msh_buffer, &tmp, sizeof(int));

}

void unmarshal2() {
    //declare currentSize to be the size of this field
    int msh_currentSize = 0;
    //copy the size of the current field into currentSize
    memcpy(&msh_currentSize, msh_cursor, sizeof(int));
    msh_cursor += sizeof(int);
    //Now copy the setspec here
    {
	MarshaledBar  var(msh_cursor, 'u');
	Shadowed_param->b = var.unmarshal();

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
#endif

