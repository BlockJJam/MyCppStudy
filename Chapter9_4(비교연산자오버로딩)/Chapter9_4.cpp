/*
	�񱳿����� �����ε��ϱ�
		-> == , !=, > , < ...
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	friend bool operator ==  (const Cents &c1, const Cents& c2)
	{
		return c1._cents == c2._cents;
	}

	friend bool operator <(const Cents &c1, const Cents &c2)
	{
		return c1._cents < c2._cents;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents cents)
	{
		out << cents._cents;
		return out;
	}
};

int main()
{
	// == ��
	Cents cents1(6), cents2(2);
	if (cents1 == cents2)
		cout << "Equal" << endl;
	else
		cout << "not Equal" << endl;

	//
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; i++)
		arr[i].getCents() = i;
	random_shuffle(begin(arr), end(arr));

	for (auto &e : arr)
		cout << e << " ";
	cout << endl;

	sort(begin(arr), end(arr));			// ǥ�� ���̺귯���� sort�� �ϸ� CentŸ���� ���� ���� �����Ϸ���

	for (auto &e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
}