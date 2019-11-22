/*
	객체잘림과 reference wrraper
		객체잘림 -> 작은 객체가 큰 자식객체를 담으려 할 때 생기는 현상
		reference wrapper -> 객체잘림 현상을 막기위한 방식
*/

#include <iostream>
#include <vector>
#include <functional>			// functional -> reference_wrapper

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

class Derived : public Base
{
public:
	int _j = 1;

	virtual void print() override
	{
		cout << "I'm derived " << endl;
	}
};

void doSomething(Base &b)			// & b가 아닌 그냥 b를 즉, 참조를 없애면 그냥 Base 객체를 복사
{
	b.print();
}

int main()
{
	//Derived d;
	////Base &b = d;
	//Base b = d;			// 다형성이 없어지고, d 객체를 그냥 복사

	//b.print();

	//doSomething(d);

	Base b;
	Derived d;

	std::vector<reference_wrapper<Base>> my_vec;		// = vector<Base&> my_vec; 
												// my_vec는 Base의 참조를 담는 벡터라는 의미
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto & ele : my_vec)
		ele.get().print();

	return 0;
}