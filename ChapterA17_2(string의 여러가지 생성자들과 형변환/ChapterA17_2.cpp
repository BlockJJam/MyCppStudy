/*
	문자열을 초기화할 때 편리하게 사용할 수 있는 편리한 생성자, string -> 기본형 or 기본형 -> string 형변환에 대해
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string ToString(T x)
{
	ostringstream osstream;

	osstream << x;
	return osstream.str();
}

template <typename T> 
bool FromString(const string &str, T &x)
{
	istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main()
{
	string my_string("my string");
	//const char * my_string("my string");

	string second_string(my_string,3);			// 앞에 3개 짤림 , const char *는 앞에 3개 가져옴
	string second_string2(my_string, 3,5);		// 앞에 3개부터 5개 가져오기
	
	string second_string3(10, 'a');				// a 10개

	cout << second_string3 << endl;	

	// stl lib의 itr을 이용해 string 초기화
	vector<char> vec;
	for (auto e : "Today is a good day")
		vec.push_back(e);

	string second_string4(vec.begin(), vec.end());
	string second_string5(vec.begin(), find(vec.begin(), vec.end(), 's'));	// s앞까지 초기화
	cout << second_string5 << endl;
	
	// 유용한 것
	string my_str(to_string(1000));		// 정수라 안되는 걸 to_string()으로 가능

	my_str += to_string(128);			// 1128? no 1000128( "1000"+"128")
	int i = stoi(my_str);
	float f = stof(my_str);
	double d = stod(my_str);

	cout << my_str << endl;
	cout << typeid(i).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(d).name() << endl;

	// 특별한 방식
	my_str =ToString("Hello");

	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "Cannot covert string to double" << endl;
	
	cout << my_str << endl;

	return 0;
}