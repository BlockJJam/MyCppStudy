// 비슷한 유형의 다양한 옵션을 기호로 표현하는 방법

#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>

using namespace std;

//열거 안쓴거
int computeDamage(int weapon_id)
{
	if (weapon_id == 0)			// sword
	{
		return 1;
	}

	if (weapon_id == 1)			// hammer
	{
		return 2;
	}
	//..
}

//열거형
enum Color						// user-defined data types
{
	COLOR_BLACK = -3,
	COLOR_RED,
	COLOR_BLUE = 5,				// color와 feeling의 BLUE가 같으면 에러, enum 클래스를 써야되는데 그건 뒤에
	COLOR_GREEN = 5,
	COLOR_SKYBLUE,
};

enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
	BLUE,
};


int main()
{
	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };	// uniform intialization은 다른 타입 초기화랑은 조금 다름

	cout << paint << " " << COLOR_RED << endl;

	if (COLOR_BLUE == BLUE)
	{
		cout << " EQUAL " << endl;
	}

	//정수형에 enum 값을 넣을 수 있나요?
	int color_id = COLOR_BLACK;

	// Color my_color = 3; 얘는 안돼
	Color my_color = static_cast<Color>(3);		// 애는 돼

	// int값으로 enum color값 넣기
	int in_number;
	cin >> in_number;

	if (in_number == 0)
		my_color = COLOR_BLACK;
	cout << my_color << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//....

	// string으로 enum color값 넣기
	string str_input;

	std::getline(cin, str_input);

	if (str_input == "COLOR_BLACK")
		my_color = static_cast<Color>(0);

	cout << my_color << endl;
	return 0;
}