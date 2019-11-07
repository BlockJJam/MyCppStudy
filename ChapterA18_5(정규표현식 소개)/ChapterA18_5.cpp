/*
	정규표현식 소개
*/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	//regex re("\\d+");		// \d 숫자냐?(숫자하나)
	//regex re("[ab]");
	//regex re("[[:digit:]]{3}"); // [:digit:] = \d 이고 {3} 3개만 딱 받겠다
	//regex re("[A-Z]+");
	//regex re("[A-Z]{3}");
	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	//{1,4}는 범위

	string str;
	
	while (true)
	{
		getline(cin, str);
		
		if (regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match " << endl;

		// print match 매치되는 부분만 
		{
			auto begin = sregex_iterator(str.begin(), str.end(), re);
			auto end = sregex_iterator();
			for (auto itr = begin; itr != end; itr++)
			{
				smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
			cout << endl;
		}
	}

	return 0;
}