// ����� ������ �پ��� �ɼ��� ��ȣ�� ǥ���ϴ� ���

#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>

using namespace std;

//���� �Ⱦ���
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

//������
enum Color						// user-defined data types
{
	COLOR_BLACK = -3,
	COLOR_RED,
	COLOR_BLUE = 5,				// color�� feeling�� BLUE�� ������ ����, enum Ŭ������ ��ߵǴµ� �װ� �ڿ�
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
	Color apple{ COLOR_RED };	// uniform intialization�� �ٸ� Ÿ�� �ʱ�ȭ���� ���� �ٸ�

	cout << paint << " " << COLOR_RED << endl;

	if (COLOR_BLUE == BLUE)
	{
		cout << " EQUAL " << endl;
	}

	//�������� enum ���� ���� �� �ֳ���?
	int color_id = COLOR_BLACK;

	// Color my_color = 3; ��� �ȵ�
	Color my_color = static_cast<Color>(3);		// �ִ� ��

	// int������ enum color�� �ֱ�
	int in_number;
	cin >> in_number;

	if (in_number == 0)
		my_color = COLOR_BLACK;
	cout << my_color << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//....

	// string���� enum color�� �ֱ�
	string str_input;

	std::getline(cin, str_input);

	if (str_input == "COLOR_BLACK")
		my_color = static_cast<Color>(0);

	cout << my_color << endl;
	return 0;
}