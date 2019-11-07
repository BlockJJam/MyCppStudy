#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int *ptr = nullptr;

	CustomVector(const unsigned & _n_data, const int & _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);
	}

	CustomVector(CustomVector & l_input)			// 복사개념
	{
		cout << "Copy constructor" << endl;

		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; i++)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector && r_input)			// r_input 소스 그대로 가져온다
	{
		cout << "Move constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned & _n_data, const int & _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; i++)
			ptr[i] = _init;
	}
};

void doSomething(CustomVector & vec)
{
	cout << "Pass by L-reference" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector && vec)			// vec 자체는 l-value이지만, move 함수를 써서 명시적으로 r-value로 넘겨줘야 한다
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));		// r-value를 넘김
	//CustomVector new_vec(vec);				// l-value
}

template<typename T>
void doSomethingTemplate(T&& vec)
{
	cout << "Forward by ref" << endl;
	doSomething(forward<T>(vec));
}

int main()
{
	CustomVector my_vec(10, 1024);

	//CustomVector temp(std::move(my_vec));		// r-value면 temp 에게 다 뺐김
	//
	//cout << my_vec.n_data << endl;

	/*doSomething(my_vec);
	doSomething(CustomVector(10, 8));*/

	//template를 한다면?
	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10, 8));

	cout << my_vec.n_data << endl;
	return 0;
}