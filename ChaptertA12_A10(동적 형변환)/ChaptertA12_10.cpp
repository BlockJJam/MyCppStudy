/*
	동적 형변환
		-> 자식에서 부모, 부모에서 자식으로 캐스팅
		-> 급한 경우 아니면 사용 X  권장
		-> functional 사용, lambda 등등 사용
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int _j = 1024;

	virtual void print() override
	{
		cout << "I'm derived1 " << endl;
	}
};

class Derived2 : public Base
{
public:
	string _name = "Dr.Tow";

	virtual void print() override
	{
		cout << "I'm derived2 " << endl;
	}
};

int main()
{
	Derived1 d1;
	Base *base = &d1;
	d1._j = 2048;

	auto *base_to_d1 = dynamic_cast<Derived1*> (base);		// 동적캐스팅은 실패하면 nullptr을 넣어버림
															// statice 캐스팅은 최대한 될 수 있는대로 다 함 
	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "Failed" << endl;
	
	//base_to_d1->_j = 256;

	//cout << d1._j << endl;

	return 0;
}