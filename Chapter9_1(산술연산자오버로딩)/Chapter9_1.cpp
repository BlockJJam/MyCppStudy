/*
	��� ������ �����ε� �ϱ�
		-> �����ؾ� �� �� : ( ?:(����) , ::(����������), sizeof, .(��� ������?), .*(��������ͼ�����?) �� �ȵ�
							^ �켱������ �ſ� ���� ������ �����ε� ���ϴ°� ����
*/

#include <iostream>

using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	friend Cents operator +(const Cents &c1, const Cents &c2)		// friends �Լ�
	{
		return (c1.getCents() + c2.getCents());
	}

	Cents operator -( const Cents &c2)								// ��� �Լ��� ��������� �����ε�
	{
		return (this->_cents + c2.getCents());
	}
	// ����θ� �ؾߵǴ� ������ ( = ,[...] , (...), -> 
};

// ��� ������ ���� ����
Cents add(const Cents &c1, const Cents &c2)		// ���� ��ȯ �Ű������� ���� �ʰ� ��ȯ Ÿ���� ���
{
	return (c1.getCents() + c2.getCents());
}

// ��� ������ operater �̿�
//Cents operator +(const Cents &c1, const Cents &c2)		
//{
//	return (c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	/*Cents sum;
	add(cents1, cents2, sum);*/

	cout << add(cents1,cents2).getCents() << endl;		// add�� ���ְ� �ʹ�
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;	// �͸�ü�� ����ؼ� 6�� ���ϰ� �ʹ�
	// getCents()�� ���ְ� �ʹ�
	cout << (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;
	
	return 0;
}