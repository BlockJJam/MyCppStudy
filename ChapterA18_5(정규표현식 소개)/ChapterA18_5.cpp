/*
	����ǥ���� �Ұ�
*/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	//regex re("\\d+");		// \d ���ڳ�?(�����ϳ�)
	//regex re("[ab]");
	//regex re("[[:digit:]]{3}"); // [:digit:] = \d �̰� {3} 3���� �� �ްڴ�
	//regex re("[A-Z]+");
	//regex re("[A-Z]{3}");
	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	//{1,4}�� ����

	string str;
	
	while (true)
	{
		getline(cin, str);
		
		if (regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match " << endl;

		// print match ��ġ�Ǵ� �κи� 
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