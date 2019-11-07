/*
	�⺻Ŭ������ ���鶧 �ڽ�Ŭ�������� �̷��̷��� �ؾ߸� �Ѵٴ� �������� �ο�( �ڽ��� �ݵ�� �������̵� )
	���� �����Լ�(pure)				: �ٵ� ���� �Լ�, �� �Լ��� �ڽ� Ŭ�������� ������! ������
	�߻� �⺻Ŭ����(abstract)		: ���� �����Լ��� ���Ե� Ŭ������ �߻�Ŭ������ �Ѵ�
	�������̽�Ŭ����(interface)		: ���� �����Լ��θ� �̷���� Ŭ����, �߰迪��
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

void Animal::speak() const				// pure virtual function body <- �ʿ���� ���
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
	//Animal ani("hi"); // ���������Լ��� �� �߻�Ŭ������ �ν��Ͻ��� ���� �� ����
	//ani speak();

	Cow cow("cow1");			// �ڽ�Ŭ������ �־���� ���������Լ��� ����
	cow.speak();

	return 0;
}