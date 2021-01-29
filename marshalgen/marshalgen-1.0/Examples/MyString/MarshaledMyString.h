// This file was generated automatically by marshalgen.
// Edit the .msh file and re-run:  marshalgen < XXX.msh


#include "MyString.h"


#ifndef MarshaledMyString_H
#define MarshaledMyString_H

#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

  class MarshaledMyString;

  class ShadowedMarshaledMyString : public MyString{
    friend class MarshaledMyString;
};

  class MarshaledMyString : public MarshaledObj {
public:
    MyString* param;
    ShadowedMarshaledMyString* Shadowed_param;
public:


// Function implementations

MarshaledMyString(MyString* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledMyString*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
    marshal2();
}

MarshaledMyString(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledMyString() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

MyString* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new MyString();
        this->Shadowed_param = (ShadowedMarshaledMyString*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
        return this->param;
    }
}

void unmarshalTo(MyString* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledMyString*)this->param;
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
      msh_currentSize = sizeof(int);

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
	memcpy(msh_cursor, &Shadowed_param->len, sizeof(int));
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
	memcpy(&Shadowed_param->len, msh_cursor, sizeof(int));

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
 
		     msh_currentSize = param->length(); 
		  
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
 
             memcpy(msh_cursor, param->buffer, param->length());
		     *(msh_cursor+param->length()) = '\0'; 
		  
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
 
             param = new MyString(msh_cursor);
		  
    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
#endif

