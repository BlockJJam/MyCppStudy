/*
	������ ���� ��ġ�� �����Ͽ� �����ϱ�
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	//make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; i++)
			ofs << i;
		ofs << endl;
	}

	//read the file
	{
		ifstream ifs(filename);
		
		ifs.seekg(5); //ifs.seekg(5,ios::beg);	���� ó������ 5����Ʈ �ĺ��͸� �о��
		cout << (char)ifs.get() << endl;
		
		ifs.seekg(5, ios::cur);					// ���� �о���� ��ġ���� �ٽ� 5����Ʈ�� �̵��ؼ�! �о�ٶ� abcde f!, ghijk l!
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-3, ios::end);				// ios::end ����������, -5�� �ڷ�~
		//cout << (char)ifs.get() << endl;

		//ifs.seekg(0, ios::end);
		//cout << ifs.tellg() << endl;			// tellg()�� ������ġ�� �����ش�

		string str;
		getline(ifs, str);

		cout << str << endl;					// mnop~~ z���� ��µǴµ�, ios::cur�� l���� ����� �����о���� �� ���ĺ��� ����Ѵ�
	}

	// ������ �ѹ� ��� �б⵵ �ϰ� ���⵵ �ϴ� ���̺귯��
	{
		//fstream iofs(filename, ios::in | ios::out);
		fstream iofs(filename);
		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read

		iofs.seekg(5);				// f�ڸ��� A�� �ִ´�
		iofs.put('A');				// write
	}
	return 0;
}