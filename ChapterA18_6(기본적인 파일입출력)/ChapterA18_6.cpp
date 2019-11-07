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
		ofstream ofs("my_first_file.txt",ios::app);		//ios::app <- ������ �����Ұ�� �̾���̱� ���, ios::binary	<- �ڵ����� �Ҹ��ڸ� �����ؼ� ofs.close() �ʿ����
		//ofs.open("my_first_file.dat");
		
		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}
		// ASCII ����
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		// binary�� �����ϱ�
		const unsigned num_data = 10;
		ofs.write((char *)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; i++)
			ofs.write((char*)&i, sizeof(i));

		// stream���� �����ϱ�
	}

	//reading
	if (true)
	{
		ifstream ifs("my_first_file.txt");				// ASCII�� �����ϸ� ������ ����, binary�� ������ ������

		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}
		// ASCII �б�
		/*while (ifs)
		{
			string str;
			getline(ifs, str);
			cout << str << endl;
		}*/
		
		//binary�� �б�
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