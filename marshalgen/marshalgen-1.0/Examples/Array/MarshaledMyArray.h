// This file was generated automatically by marshalgen.

#ifndef MarshaledMyArray_H
#define MarshaledMyArray_H


#include <MyArray.h>


#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

  class MarshaledMyArray;

  class ShadowedMarshaledMyArray : public MyArray{
    friend class MarshaledMyArray;
};

  class MarshaledMyArray : public MarshaledObj {
public:
    MyArray* param;
    ShadowedMarshaledMyArray* Shadowed_param;
public:


// Function implementations

MarshaledMyArray(MyArray* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledMyArray*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
}

MarshaledMyArray(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledMyArray() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

MyArray* unmarshal() {
    //We don't want to unmarshal the buffer is empty.
    if(msh_size <= MSH_HEADER_SIZE) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        {
	param = new MyArray();
	}
        this->Shadowed_param = (ShadowedMarshaledMyArray*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        return this->param;
    }
}

void unmarshalTo(MyArray* obj) {
    //We don't want to unmarshal the buffer is empty.
    if(msh_size <= MSH_HEADER_SIZE) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledMyArray*)this->param;
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

    }

    //Increase the size of buffer if needed
    EXTEND_BUFFER(msh_currentSize + sizeof(int) + sizeof(int)); // 4 bytes for the total size of field, 4 bytes for the number of elements in the array (in the case of array marshaling)
    //Mark the beginning position for this field, will write the total size of this field here later
    msh_field_begin = msh_cursor;

    //Advance cursor of distance = sizeof(int)
    msh_cursor += sizeof(int);

    //Now just copy "get" functions here
    {
	int copy_off = 0;
	int elementNum;
	 elementNum = param->count; 
	memcpy( msh_cursor+copy_off, &elementNum,sizeof(int));
	copy_off += sizeof(int);
	for(int index=0;index<elementNum;index++){
			double  anElement;
			 anElement = param->HC[index]; 
			EXTEND_BUFFER(sizeof(double ));
			memcpy(msh_cursor+copy_off, &anElement, sizeof(double ));
			copy_off += sizeof(double ));
		}
	msh_currentSize = copy_off;

    }
    //Now advance the cursor
    msh_cursor += msh_currentSize;
    //Now set the size of this field
    int tmp; //use memcpy instead of *(int*)... =... to prevent bus error
    tmp = (msh_cursor-msh_field_begin) - sizeof(int);
    memcpy(msh_field_begin, &tmp, sizeof(int));

    //Now set msh_size
    msh_size = msh_cursor - msh_buffer;
    MSH_SET_TOTALSIZE(msh_size);    MSH_SET_TYPECHOICE(msh_typechoice);
}

void unmarshal1() {
    //declare currentSize to be the size of this field
    int msh_currentSize = 0;
    //copy the size of the current field into currentSize
    memcpy(&msh_currentSize, msh_cursor, sizeof(int));
    msh_cursor += sizeof(int);
    //Now copy the setspec here
    {
		int copy_off = 0;
		int elementNum;
		memcpy(&elementNum, msh_cursor+copy_off, sizeof(int));
		copy_off += sizeof(int);
		for(int index=0;index<elementNum;index++){
			double  anElement;
			memcpy(&anElement,msh_cursor+copy_off, sizeof(double ));
			copy_off += sizeof(double );
			 param->HC[index] = anElement; 
		}

    }
    msh_cursor += msh_currentSize;
}

};
#endif

