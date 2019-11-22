/*
	다형성이란
		-> 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?
		-> virtual 키워드 : 부모클래스의 포인터지만 자식클래스처럼 돌림

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

	string getName()
	{
		return _name;
	}

	virtual void speak() const
	{
		cout << _name << "???" << endl;
	}
};

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

int main()
{
	/*Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	Animal *ptr_animal1 = &cat;
	Animal *ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak();*/

	Cat cats[] = { Cat("cat"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1") , Dog("dog2") };

	for (int i = 0; i < 5; i++)
		cats[i].speak();
	for (int i = 0; i < 2; i++)
		dogs[i].speak();

	Animal *my_animals[] = {&cats[0] ,&cats[1] ,&cats[2] ,&cats[3] ,&cats[4], &dogs[0], &dogs[1] };			

	for (int i = 0; i < 7; i++)										// 이것만 하면 Animal로 안다
		my_animals[i]->speak();

	return 0;
}