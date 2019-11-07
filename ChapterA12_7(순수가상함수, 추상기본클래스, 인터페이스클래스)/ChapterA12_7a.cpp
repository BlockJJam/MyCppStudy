/*
	기본클래스를 만들때 자식클래스에게 이러이런걸 해야만 한다는 강제성을 부여( 자식이 반드시 오버라이딩 )
	순수 가상함수(pure)				: 바디가 없는 함수, 이 함수를 자식 클래스에서 무조건! 만들어라
	추상 기본클래스(abstract)		: 순수 가상함수가 포함된 클래스를 추상클래스라 한다
	인터페이스클래스(interface)		: 순수 가상함수로만 이루어진 클래스, 중계역할
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string _name;

public:
	Animal(string name)
		: _name(name)
	{}

public:
	string getName()
	{
		return _name;
	}

	virtual void speak() const = 0;		// =0? pure virtual Function 

};

void Animal::speak() const				// pure virtual function body <- 필요없음 사실
{
	cout << _name << " ??? " << endl;
}

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << _name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << _name << " Woof" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}

	virtual void speak() const
	{
		cout << _name << " Moo~" << endl;
	}
};

int main()
{
	//Animal ani("hi"); // 순수가상함수가 들어간 추상클래스는 인스턴스를 만들 수 없다
	//ani speak();

	Cow cow("cow1");			// 자식클래스에 있어야할 순수가상함수가 없다
	cow.speak();

	return 0;
}