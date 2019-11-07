/*
	exception �Ұ�( standard lib)
*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class CustomException :public exception
{
public:
	const char * what() const noexcept override			// C++11�̻��� exception�� ����� ���� �� noexcept�� �ٿ�����Ѵ�( �ǹ�: �� �ȿ� �Լ��� no execption�� �Ѵ�)
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{	
		//string s;
		//s.resize(-1);						// string too long <- unsigned��
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