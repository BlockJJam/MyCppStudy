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

	CustomVector(CustomVector & l_input)			// ���簳��
	{
		cout << "Copy constructor" << endl;

		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; i++)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector && r_input)			// r_input �ҽ� �״�� �����´�
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

void doSomething(CustomVector && vec)			// vec ��ü�� l-value������, move �Լ��� �Ἥ ��������� r-value�� �Ѱ���� �Ѵ�
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));		// r-value�� �ѱ�
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

	//CustomVector temp(std::move(my_vec));		// r-value�� temp ���� �� ����
	//
	//cout << my_vec.n_data << endl;

	/*doSomething(my_vec);
	doSomething(CustomVector(10, 8));*/

	//template�� �Ѵٸ�?
	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10, 8));

	cout << my_vec.n_data << endl;
	return 0;
}