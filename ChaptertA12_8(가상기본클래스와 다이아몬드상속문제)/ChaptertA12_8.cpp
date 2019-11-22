/*
	가상 기본클래스, 다이아몬드 상속 문제
*/

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int _i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice : " << power << endl;
	}
};

class Scanner : virtual public PoweredDevice			// 다이아몬드 문제를 해결하기 위한, 가상기본클래스를 이용
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << '\n';
	}
};

class Printer :virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public: 
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)		// 왜 가상기본클래스를 이용하면 최상위클래스를 다시 생성자를 호출해야 할까? 
																						// 간단하게 다이아몬드 문제를 해결하기 위해 하나의 최상위클래스주소만 따로 불러오니까
	{}
};	

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::_i << endl;
	cout << &cop.Printer::PoweredDevice::_i << endl;		// 즉 Scanner와 Printer의 PowerDevice의 주소는 서로 다르다

	return 0;
}