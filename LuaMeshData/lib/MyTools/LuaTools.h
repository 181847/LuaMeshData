#pragma once
#include "DLLTools.h"
#include "MyAssert.h"
#include "MyTools.h"
#include <functional>

// this head file contain some tools for writing c module for lua

// this is the container which store the pointer of the user.
template<typename T>
struct LuaPointerContainer
{
public:
	T * pointer;

	void setPointer(T * p)
	{
		pointer = p;
		cleaner = [p]() {if (p) delete p; };
	}

	T * operator -> () const
	{
		return pointer;
	}
};
