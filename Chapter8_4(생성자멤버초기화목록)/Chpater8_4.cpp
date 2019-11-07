#include <iostream>

using namespace std;

class B
{
private :
	int _b;
	
public :
	B(const int& m_b_in)
		:_b{ m_b_in } {};
};

class Something
{
private:
	int _i;
	double _d;
	char _c;
	int  _arr[5];
	B _b;
public:
	//initializer list
	Something()														// 초기화는 private에서 초기화해주는 것과 생성자에서 초기화해주는 것중 무엇이 우선일까? 생성자 !
		:_i{ 1 }, _d{ 3.14 }, _c{ 'a' }, _arr{ 1,2,3,4,5 }, _b{ _i - 1 }{}

	void print()
	{
		cout << _i << " " << _d << " " << _c << endl;
		for (auto &mem : _arr)
			cout << mem << " ";
		cout << endl;
		//cout << _b << endl;
	}
};

int main()
{
	Something st;

	st.print();

	return 0;
}
