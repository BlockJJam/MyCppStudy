#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < _length; i++)
		std::cout << _data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation -> 내가 직접 explicit해서 타입을 찾아갈 수 있도록

//template void MyArray<char>::print();		// char
//template void MyArray<double>::print();		// double

// class 자체를 template explicit해준다
template class MyArray<char>;
template class MyArray<double>;