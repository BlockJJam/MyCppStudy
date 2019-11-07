#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < _length; i++)
		std::cout << _data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation -> ���� ���� explicit�ؼ� Ÿ���� ã�ư� �� �ֵ���

//template void MyArray<char>::print();		// char
//template void MyArray<double>::print();		// double

// class ��ü�� template explicit���ش�
template class MyArray<char>;
template class MyArray<double>;