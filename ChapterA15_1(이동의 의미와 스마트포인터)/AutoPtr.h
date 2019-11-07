#pragma once

#include <iostream>

// std::auto_ptr <int>; // c++ 98,11, 17�� ���Ŀ��鼭 ����� -> ��� X

template <class T>
class AutoPtr
{
public:
	T *_ptr = nullptr;

public:
	AutoPtr(T *ptr = nullptr)
		: _ptr(ptr)
	{
	}

	~AutoPtr()
	{
		if (_ptr != nullptr)
			delete _ptr;
	}

	T& operator*() const { return *_ptr; }
	T* operator->() const { return _ptr; }
	bool isNull() const { return _ptr == nullptr; }

	AutoPtr(AutoPtr &a)							// contructor	(������ ����)
	{
		_ptr = a._ptr;
		a._ptr = nullptr;
	}

	AutoPtr & operator = (AutoPtr &a)			// assign operator	( ������ ���� )
	{
		if (&a == this)
			return *this;

		delete _ptr;
		_ptr = a._ptr;
		a._ptr = nullptr;
		return *this;
	}

};