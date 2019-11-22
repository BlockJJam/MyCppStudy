#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
	/*bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;*/

	// 위는 1바이트를 잡아먹음 , 비트플래그를 사용
	/*
	unsigned char items_flag(0);
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;

	//item0 on
	items_flag |= opt0;
	cout << "item0 obtained " << bitset<8>(items_flag) << endl;

	//item2 on 
	items_flag |= opt2;
	cout << "item2 obtained " << bitset<8>(items_flag) << endl;

	//item2 lost
	items_flag &= ~opt2;
	cout << "item2 lost " << bitset<8>(items_flag) << endl;

	//item3 on
	items_flag |= opt3;
	cout << "item3 obtained " << bitset<8>(items_flag) << endl;

	// has item1?
	if (items_flag & opt1)
		cout << "Has item1" << endl;
	else
		cout << "not Has item1" << endl;

	// has item0?
	if (items_flag & opt0)
		cout << "Has item0" << endl;
	else
		cout << "not Has item0" << endl;

	//obtain item 2,3
	items_flag |= (opt2 | opt3);
	cout << bitset<8>(items_flag) << endl;
	cout << "item 2,3 obtained " << bitset<8>(items_flag) << endl;

	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		items_flag ^= (opt2 | opt1);
	}
	
	cout << bitset<8>(items_flag) << endl;
	*/
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	unsigned int pixel_color = 0xDAA520;

	cout << bitset<32>(pixel_color) << endl;
	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;

	unsigned int red, green, blue;

	/*red = ( pixel_color & red_mask) >>16;
	green = (pixel_color & green_mask) >> 8;
	blue = pixel_color & blue_mask;
	cout << "red rgb    : "<< bitset<8>(red) << endl;
	cout << "green rgb  : " << bitset<8>(green) << endl;
	cout << "blue rgb   : " << bitset<8>(blue) << endl;*/

	red = pixel_color & red_mask;
	green = pixel_color & green_mask;
	blue = pixel_color & blue_mask;
	cout << "red rgb    : " << bitset<32>(red) << endl;
	cout << "green rgb  : " << bitset<32>(green) << endl;
	cout << "blue rgb   : " << bitset<32>(blue) << endl;

	return 0;
}