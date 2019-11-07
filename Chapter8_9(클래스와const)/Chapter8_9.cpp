/*
	class와 const
		-> const로 만들 수 있는 코드는 왠만하면 다 만들어두자
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
	int getValue() const						// const를 붙여줘야 멤버를 변경하지 않겠다는 의미 , 복잡한 함수에 const 쓸 수 있는곳은 거의 막아놔야 좋다( 디버깅에 유리 )
	{
		return _value;
	}
};

class Something2								// const 오버로딩 예제
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

void print(const Something &st)					// (참조가 아니면)클래스 매개변수도 copy, 복사형태지만 주소가 다르고 새로 생성된다고 해서 새로운 생성자를 호출하는게 아니라 복사생성자를 새로 호출한다(그냥 생성자랑은 다름)
{
	cout << &st << endl;
	cout << st.getValue() << endl;
}

int main()
{
	const Something something;

	//something.setValue(3);	<- const로 객체를 선언하면 객체의 멤버를 변경 X
	cout << something.getValue() << endl;
	cout << &something << endl;

	print(something);

	// const 유무로 오버로딩 가능
	Something2 st1;
	st1.getValue() =10;

	const Something2 st2;
	st2.getValue() = 1024;		// const라 허용안됨


	return 0;
}
