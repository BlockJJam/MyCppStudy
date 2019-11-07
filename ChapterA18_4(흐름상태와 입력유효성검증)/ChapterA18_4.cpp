/*
	의도한 입력값을 받았는 지 확인하고 싶을 때
	흐름상태와 입력유효성 검증하기
*/

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

// 내가 원하는 문자인지 검증
void printCharacterClassification(const int & i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(isalnum(i)) << endl;
	cout << "isblank " << bool(isblank(i)) << endl;
	cout << "isdigit " << bool(isdigit(i)) << endl;
	cout << "islower " << bool(islower(i)) << endl;
	cout << "isupper " << bool(isupper(i)) << endl;
	cout << "-----------------------------" << endl;

}

// stream 상태확인방법 1) 더 좋은방식
void printStates(const std::ios & stream)
{
	cout << boolalpha;
	cout << "good()= " << stream.good() << endl;
	cout << "eof()=  " << stream.eof() << endl;		// 파일을 다 읽었는지
	cout << "fail()= " << stream.fail() << endl;	// 실패했는지
	cout << "bad()= " << stream.bad() << endl;		// 안좋은
	cout << "-----------------------------" << endl;
}


bool classifyCharacters(const string & str)
{
	bool ok_flag = true;
	
	for (auto e : str)
	{
		cout << "chr : " << e << endl;
		cout << "isdigit " << std::isdigit(e) << endl;
		cout << "isblank " << isblank(e) << endl;
		cout << "isalpha " << isalpha(e) << endl;
	}

	/*for (auto e : str)
	{
		if (!isdigit(e))
		{
			ok_flag = false;
			break;
		}
	}*/
	return ok_flag;
}

int main()
{
	//while (true)
	//{
	//	char i;
	//	cin.get(i);

	//	printStates(cin);

	//	cout << i << endl;

	//	// stream 상태확인방법 2) 별로.. / 퍼포먼스적으로 최적화에는 도움
	//	/*cout << boolalpha;
	//	cout << bitset<8>(cin.rdstate()) << endl;
	//	cout << bitset<8>(istream::goodbit) << endl;
	//	cout << bitset<8>(istream::failbit) << endl;
	//	cout << !bool((cin.rdstate() & istream::failbit) != 0) << endl;*/

	//// 문자의 형태 확인
	//	printCharacterClassification(i);

	//	cin.clear();
	//	cin.ignore(1024, '\n');
	//	cout << endl;
	//}

	// 정말 원하는 형태로 들어왔는지
	cout << boolalpha;
	classifyCharacters("1234");
	classifyCharacters("a 1234");
	return 0;

	// 실제로 정규식을 이용하면 더 원하는 형태 검증이 쉬움

}