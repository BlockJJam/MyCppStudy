/*
	파일의 임의 위치에 접근하여 조작하기
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
		
		ifs.seekg(5); //ifs.seekg(5,ios::beg);	파일 처음부터 5바이트 후부터를 읽어라
		cout << (char)ifs.get() << endl;
		
		ifs.seekg(5, ios::cur);					// 현재 읽어들인 위치부터 다시 5바이트를 이동해서! 읽어바라 abcde f!, ghijk l!
		cout << (char)ifs.get() << endl;

		//ifs.seekg(-3, ios::end);				// ios::end 끝에서부터, -5는 뒤로~
		//cout << (char)ifs.get() << endl;

		//ifs.seekg(0, ios::end);
		//cout << ifs.tellg() << endl;			// tellg()는 현재위치를 말해준다

		string str;
		getline(ifs, str);

		cout << str << endl;					// mnop~~ z까지 출력되는데, ios::cur이 l까지 출력한 현재읽어들인 곳 이후부터 출력한다
	}

	// 파일을 한번 열어서 읽기도 하고 쓰기도 하는 라이브러리
	{
		//fstream iofs(filename, ios::in | ios::out);
		fstream iofs(filename);
		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read

		iofs.seekg(5);				// f자리에 A를 넣는다
		iofs.put('A');				// write
	}
	return 0;
}