/*
	���� �⺻Ŭ����, ���̾Ƹ�� ��� ����
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

class Scanner : virtual public PoweredDevice			// ���̾Ƹ�� ������ �ذ��ϱ� ����, ����⺻Ŭ������ �̿�
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
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)		// �� ����⺻Ŭ������ �̿��ϸ� �ֻ���Ŭ������ �ٽ� �����ڸ� ȣ���ؾ� �ұ�? 
																						// �����ϰ� ���̾Ƹ�� ������ �ذ��ϱ� ���� �ϳ��� �ֻ���Ŭ�����ּҸ� ���� �ҷ����ϱ�
	{}
};	

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::_i << endl;
	cout << &cop.Printer::PoweredDevice::_i << endl;		// �� Scanner�� Printer�� PowerDevice�� �ּҴ� ���� �ٸ���

	return 0;
}