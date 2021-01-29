// This file was generated automatically by marshalgen.
// Edit the .msh file and re-run:  marshalgen < XXX.msh


#include "MyTemplate2.h"


#ifndef MarshaledMyTemplate2_H
#define MarshaledMyTemplate2_H

#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

  class MarshaledMyTemplate2;

  class ShadowedMarshaledMyTemplate2 : public MyTemplate2{
    friend class MarshaledMyTemplate2;
};


  class MarshaledBar2;

  class ShadowedMarshaledBar2 : public Bar2{
    friend class MarshaledBar2;
};

  class MarshaledMyTemplate2 : public MarshaledObj {
public:
    MyTemplate2* param;
    ShadowedMarshaledMyTemplate2* Shadowed_param;
public:


// Function implementations

MarshaledMyTemplate2(MyTemplate2* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledMyTemplate2*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
}

MarshaledMyTemplate2(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledMyTemplate2() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

MyTemplate2* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new MyTemplate2();
        this->Shadowed_param = (ShadowedMarshaledMyTemplate2*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        return this->param;
    }
}

void unmarshalTo(MyTemplate2* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledMyTemplate2*)this->param;
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
		MarshaledBar2 var(&Shadowed_param->data);
		msh_currentSize = var.getBufferSize();
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
		MarshaledBar2 var(&Shadowed_param->data);
		memcpy(msh_cursor, var.getBuffer(), var.getBufferSize());
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
		MarshaledBar2 var(msh_cursor, 'u');
		var.unmarshalTo(&Shadowed_param->data);
	}

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
  class MarshaledBar2 : public MarshaledObj {
public:
    Bar2* param;
    ShadowedMarshaledBar2* Shadowed_param;
public:


// Function implementations

MarshaledBar2(Bar2* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledBar2*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
    marshal2();
}

MarshaledBar2(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledBar2() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

Bar2* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new Bar2();
        this->Shadowed_param = (ShadowedMarshaledBar2*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
        return this->param;
    }
}

void unmarshalTo(Bar2* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledBar2*)this->param;
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
	msh_currentSize = sizeof(double);

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
	memcpy(msh_cursor, &Shadowed_param->x, sizeof(double));
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
	memcpy(&Shadowed_param->x, msh_cursor, sizeof(double));

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
	msh_currentSize = sizeof(double);

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
	memcpy(msh_cursor, &Shadowed_param->y, sizeof(double));
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
	memcpy(&Shadowed_param->y, msh_cursor, sizeof(double));

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
#endif

