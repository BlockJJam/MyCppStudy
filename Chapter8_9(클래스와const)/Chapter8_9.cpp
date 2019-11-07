/*
	class�� const
		-> const�� ���� �� �ִ� �ڵ�� �ظ��ϸ� �� ��������
*/

#include <iostream>
#include <string>

using namespace std;

class Something
{
private:
	int _value = 0;

public : 
	Something(const Something& st_in)		// Copy Constructor
	{
		_value = st_in._value;

		cout << "Copy Constructor" << endl;
	}

	Something()
	{
		cout << "Constructor" << endl;
	}

	void setValue(int value)
	{
		_value = value;
	}
	int getValue() const						// const�� �ٿ���� ����� �������� �ʰڴٴ� �ǹ� , ������ �Լ��� const �� �� �ִ°��� ���� ���Ƴ��� ����( ����뿡 ���� )
	{
		return _value;
	}
};

class Something2								// const �����ε� ����
{
public:
	string _value = "default";
	const string& getValue() const {
		cout << "const version" << endl;
		return _value;
	}
	string& getValue()
	{
		cout << "non-const version" << endl;
		return _value;
	}
};

void print(const Something &st)					// (������ �ƴϸ�)Ŭ���� �Ű������� copy, ������������ �ּҰ� �ٸ��� ���� �����ȴٰ� �ؼ� ���ο� �����ڸ� ȣ���ϴ°� �ƴ϶� ��������ڸ� ���� ȣ���Ѵ�(�׳� �����ڶ��� �ٸ�)
{
	cout << &st << endl;
	cout << st.getValue() << endl;
}

int main()
{
	const Something something;

	//something.setValue(3);	<- const�� ��ü�� �����ϸ� ��ü�� ����� ���� X
	cout << something.getValue() << endl;
	cout << &something << endl;

	print(something);

	// const ������ �����ε� ����
	Something2 st1;
	st1.getValue() =10;

	const Something2 st2;
	st2.getValue() = 1024;		// const�� ���ȵ�


	return 0;
}
