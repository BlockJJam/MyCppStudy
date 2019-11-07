/*
	exception 소개( standard lib)
*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class CustomException :public exception
{
public:
	const char * what() const noexcept override			// C++11이상은 exception을 상속을 받을 때 noexcept를 붙여줘야한다( 의미: 이 안에 함수는 no execption을 한다)
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{	
		//string s;
		//s.resize(-1);						// string too long <- unsigned라서
		//throw std::runtime_error("Bad Thing Happened");
		throw CustomException();
	}
	//catch (length_error & exception)
	//{
	//	cout << "Length_error" << endl;
	//	cerr << exception.what() << endl;
	//}
	catch (exception & exception)
	{
		cout << typeid(exception).name() << endl;
		cerr << exception.what() << endl;		
	}

	return 0;
}