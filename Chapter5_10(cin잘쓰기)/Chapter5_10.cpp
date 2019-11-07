// ignore() , clear(), fail()....

#include <iostream>

using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter an int number: ";
		int x;
		cin >> x;

		if (cin.fail())						// 입력 실패했으면 
		{
			cin.clear();					// 싹 지워버리고 버퍼값을
			cin.ignore(32767, '\n');		// 공백 무시
			cout << " Invalid number, please try again" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return x;
		}
	}
}

char getOperator()
{
	while (true)
	{
		cout << " Enter an operator (+,-) : ";
		char op;
		cin >> op;
		cin.ignore(32767, '\n');

		if (op == '+' || op == '-')
			return op;
		else
			cout << "Invalid operator .. try again" << endl;
	}
}

void printResult(int x, char op, int y)
{
	switch (op)
	{
	case '+':
		cout << x + y << endl;
		break;
	case '-':
		cout << x - y << endl;
		break;
	default:
		cout << "Invalid Operator" << endl;
		break;
	}

}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);



}