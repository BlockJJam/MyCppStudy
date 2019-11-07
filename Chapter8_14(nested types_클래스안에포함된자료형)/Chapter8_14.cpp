/*
	클래스 안에 포함된 자료형 < nested types >
		-> 클래스 안에만 사용하는 자료형?
*/

#include <iostream>

using namespace std;



class Fruit
{
public:
	enum class FruitType			// 특정 클래스만 사용하는 데이터 타입의 경우는 해당 클래스 안에서 구현
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
