/*
	�ǵ��� �Է°��� �޾Ҵ� �� Ȯ���ϰ� ���� ��
	�帧���¿� �Է���ȿ�� �����ϱ�
*/

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

// ���� ���ϴ� �������� ����
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

// stream ����Ȯ�ι�� 1) �� �������
void printStates(const std::ios & stream)
{
	cout << boolalpha;
	cout << "good()= " << stream.good() << endl;
	cout << "eof()=  " << stream.eof() << endl;		// ������ �� �о�����
	cout << "fail()= " << stream.fail() << endl;	// �����ߴ���
	cout << "bad()= " << stream.bad() << endl;		// ������
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

	//	// stream ����Ȯ�ι�� 2) ����.. / �����ս������� ����ȭ���� ����
	//	/*cout << boolalpha;
	//	cout << bitset<8>(cin.rdstate()) << endl;
	//	cout << bitset<8>(istream::goodbit) << endl;
	//	cout << bitset<8>(istream::failbit) << endl;
	//	cout << !bool((cin.rdstate() & istream::failbit) != 0) << endl;*/

	//// ������ ���� Ȯ��
	//	printCharacterClassification(i);

	//	cin.clear();
	//	cin.ignore(1024, '\n');
	//	cout << endl;
	//}

	// ���� ���ϴ� ���·� ���Դ���
	cout << boolalpha;
	classifyCharacters("1234");
	classifyCharacters("a 1234");
	return 0;

	// ������ ���Խ��� �̿��ϸ� �� ���ϴ� ���� ������ ����

}