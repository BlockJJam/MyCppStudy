/*
	����ó���� �⺻
		-> ����ó���� ���̱� ������, ������������ ���� �� ���� �ʴ�
		-> ���� ���� ����ұ�? ���ͳ� ������ ���Ӽ������� ��� ����ġ �ʴ� ��Ȳ�� ����ѵ� ���񽺰� �����Ǿ� �ϴ� ���
		 

*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int findFirstChar(const char * string, char ch)
//{
//	for (std::size_t index = 0; index < strlen(string); index++)
//		if (string[index] == ch)
//			return index;
//
//	return -1;
//}
//
//double divide(int x, int y, bool &success)
//{
//	if (y == 0)
//	{
//		success = false;
//		return 0.0;
//	}
//
//	success = false;
//	return static_cast<double>(x) / y;
//}
//
//int main()
//{
//	bool success;
//	double result = divide(5, 3, success);
//
//	if (!success)
//		cerr << "An Error Occurred" << endl;
//	else
//		cerr << "Result is "  <<result << endl;
//
//	std::ifstream input_file("temp.txt");
//	if (!input_file)
//		cerr << "Cannot open file" << endl;
//
//	return 0;
//}

int main()
{
	// try, catch, throw
	//double x;
	//cin >> x;

	try
	{
		//if (x < 0.0) throw string("Negative input");		//����ó���� ĳ���ÿ� ����

		//cout << std::sqrt(x) << endl;

		// something happened
		throw string("My error message");
	}
	catch (int x)
	{
		cout << "Catch Integer "<< x << endl;
	}
	catch (double x)
	{
		cout << "Catch Double " << x << endl;
	}
	catch (const char * err_message)
	{
		cout << "Catch Char * " << err_message << endl;
	}
	catch (std::string error_message)
	{
		// do something to respond
		cout << "Catch String "<< error_message << endl;
	}
	return 0;
}