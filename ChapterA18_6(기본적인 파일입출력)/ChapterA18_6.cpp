/*
	file I/O
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//exit()
#include <sstream>
using namespace std;

int main()
{
	//writing
	if (false)
	{
		ofstream ofs("my_first_file.txt",ios::app);		//ios::app <- 파일이 존재할경우 이어붙이기 모드, ios::binary	<- 자동으로 소멸자를 생성해서 ofs.close() 필요없음
		//ofs.open("my_first_file.dat");
		
		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}
		// ASCII 쓰기
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		// binary로 저장하기
		const unsigned num_data = 10;
		ofs.write((char *)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; i++)
			ofs.write((char*)&i, sizeof(i));

		// stream으로 저장하기
	}

	//reading
	if (true)
	{
		ifstream ifs("my_first_file.txt");				// ASCII로 저장하면 굉장히 느림, binary로 저장을 많이함

		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}
		// ASCII 읽기
		/*while (ifs)
		{
			string str;
			getline(ifs, str);
			cout << str << endl;
		}*/
		
		//binary로 읽기
		unsigned num_data = 0;
			
		ifs.read((char*)&num_data, sizeof(num_data));
		
		for (unsigned int i = 0; i < num_data; i++)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}
	}
	return 0;
}