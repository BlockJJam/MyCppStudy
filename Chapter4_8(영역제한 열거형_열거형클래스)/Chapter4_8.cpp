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
	
	// color�� fruit�� 1�� ���� ������ -> Ŭ������ ����� �Ʒ�ó�� Ŭ�������̸� ������ �˷��ش�

	if (color == fruit)
	{
		cout << " Color is Fruit ? " << endl;
	}
	

	return 0;
}