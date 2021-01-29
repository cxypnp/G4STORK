// This file was generated automatically by marshalgen.
// Edit the .msh file and re-run:  marshalgen < XXX.msh


#include "MyTemplate1.h"


#ifndef MarshaledT_H
#define MarshaledT_H

#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

template <class T> class MarshaledT;

template <class T> class ShadowedMarshaledT : public T{
    friend class MarshaledT;
};

template <class T> class MarshaledT : public MarshaledObj {
public:
    T* param;
    ShadowedMarshaledT* Shadowed_param;
public:


// Function implementations

MarshaledT(T* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledT*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
}

MarshaledT(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledT() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

T* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new T();
        this->Shadowed_param = (ShadowedMarshaledT*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        return this->param;
    }
}

void unmarshalTo(T* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledT*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
    }
}

void marshal1() {
    //declare field_size to be the size of this field
    int msh_currentSize = 0;
    if (isUnmarshaling())
        throw "Tried to marshal in obj marked isUnmarshaling == true";

    //Copy the sizespec into msh_currentSize here:
    {
	if(0){}
	else if((MSH_IsSameClass<T,int>) ){
		msh_currentSize = sizeof(int);
	}
	else if( true ){
		msh_currentSize = sizeof(double);
	}

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
	if(0){}
	else if((MSH_IsSameClass<T,int>) ){
		memcpy(msh_cursor, &Shadowed_param->data, sizeof(int));
	}
	else if( true ){
		memcpy(msh_cursor, &Shadowed_param->data, sizeof(double));
	}

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
	if(0){}
	else if((MSH_IsSameClass<T,int>) ){
		memcpy(&Shadowed_param->data, msh_cursor, sizeof(int));
	}
	else if( true ){
		memcpy(&Shadowed_param->data, msh_cursor, sizeof(double));
	}

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
#endif

