// This file was generated automatically by marshalgen.
// Edit the .msh file and re-run:  marshalgen < XXX.msh


#include "Foo.h"
//MSH_include_begin
#include "MarshaledBar.h"
//MSH_include_end

#ifndef MarshaledFoo_H
#define MarshaledFoo_H

#include <stdio.h>
#include <string.h>
#include "MarshaledObj.h"

  class MarshaledFoo;

  class ShadowedMarshaledFoo : public Foo{
    friend class MarshaledFoo;
};

  class MarshaledFoo : public MarshaledObj {
public:
    Foo* param;
    ShadowedMarshaledFoo* Shadowed_param;
public:


// Function implementations

MarshaledFoo(Foo* objptr) : MarshaledObj() {
    msh_isUnmarshalDone = false;
    this->param = objptr;
    this->Shadowed_param = (ShadowedMarshaledFoo*)this->param;
    if (objptr == NULL)
        return;

    marshal1();
    marshal2();
    marshal3();
}

MarshaledFoo(void *buf, char isUnmarshaling = 'u')
: MarshaledObj(buf, isUnmarshaling) {
    msh_isUnmarshalDone = false;
}

~MarshaledFoo() {
    //if(msh_isUnmarshalDone && this->param != NULL) {
        //delete this->param;
    //}
}

Foo* unmarshal() {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return NULL;
    } else {
        this->param = new Foo();
        this->Shadowed_param = (ShadowedMarshaledFoo*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
        unmarshal3();
        return this->param;
    }
}

void unmarshalTo(Foo* obj) {
    //We don't want to unmarshal when msh_buffer is empty.
    if(*(int *)this->msh_buffer == 0) {
        //This is buggy, we can't always assume that
        //obj == NULL <==> List is empty.
        return;
    } else {
        this->param = obj;
        this->Shadowed_param = (ShadowedMarshaledFoo*)this->param;
        this->msh_isUnmarshalDone = true;
        unmarshal1();
        unmarshal2();
        unmarshal3();
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
	memcpy(msh_cursor, &Shadowed_param->x, sizeof(int));
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
	memcpy(&Shadowed_param->x, msh_cursor, sizeof(int));

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
	MarshaledBar var(&Shadowed_param->bar);
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
	MarshaledBar var(&Shadowed_param->bar);
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
	MarshaledBar var(msh_cursor, 'u');
	var.unmarshalTo(&Shadowed_param->bar);

    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

void marshal3() {
    //declare field_size to be the size of this field
    int msh_currentSize = 0;
    if (isUnmarshaling())
        throw "Tried to marshal in obj marked isUnmarshaling == true";

    //Copy the sizespec into msh_currentSize here:
    {
      msh_currentSize = sizeof( int );
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
      memcpy( msh_cursor, &$varname, sizeof( int ));
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

void unmarshal3() {
    //declare currentSize to be the size of this field
    int msh_currentSize = 0;
    //copy the size of the current field into currentSize
    memcpy(&msh_currentSize, msh_cursor, sizeof(int));
    msh_cursor += sizeof(int);
    //Now copy the setspec here
    {
      memcpy( &$varname, msh_cursor, sizeof( int ));
    }
    msh_cursor += msh_currentSize;
    msh_size = msh_cursor - msh_buffer;
}

};
#endif

