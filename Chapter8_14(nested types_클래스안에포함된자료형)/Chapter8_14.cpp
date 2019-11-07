/*
	Ŭ���� �ȿ� ���Ե� �ڷ��� < nested types >
		-> Ŭ���� �ȿ��� ����ϴ� �ڷ���?
*/

#include <iostream>

using namespace std;



class Fruit
{
public:
	enum class FruitType			// Ư�� Ŭ������ ����ϴ� ������ Ÿ���� ���� �ش� Ŭ���� �ȿ��� ����
	{
		APPLE,
		BANANA,
		CHERRY,
	};
	
	class InnerClass
	{

	};

	struct InnerStruct
	{
		
	};

private:
	FruitType _type;

public:
	Fruit(FruitType type)
		: _type(type)
	{}

	FruitType getType()
	{
		return _type;
	}
};

int main()
{
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		cout << "apple" << endl;
	}


	return 0;
}
