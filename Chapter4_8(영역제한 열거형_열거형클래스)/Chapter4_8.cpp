#include <iostream>

int main()
{
	using namespace std;

	enum class Color
	{
		RED,
		BLUE,
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};
	
	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;
	
	// color와 fruit에 1이 들어가기 때문에 -> 클래스로 만들면 아래처럼 클래스차이를 오류로 알려준다

	if (color == fruit)
	{
		cout << " Color is Fruit ? " << endl;
	}
	

	return 0;
}