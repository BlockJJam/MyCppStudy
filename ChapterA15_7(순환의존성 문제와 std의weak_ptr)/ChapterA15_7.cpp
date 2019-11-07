/*
	��ȯ������ ����, weak_ptr
*/

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
	string _name;
	//shared_ptr<Person> _partner;
	weak_ptr<Person> _partner;

public:
	Person(const string &name)
		:_name(name)
	{
		cout << _name << " created \n";
	}

	~Person()
	{
		cout << _name << " destroyed \n";
	}

	friend bool partnerUp(shared_ptr<Person> &p1, shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->_partner = p2;
		p2->_partner = p1;

		cout << p1->_name << " is partnered with " << p2->_name << "\n";

		return true;
	}

	const shared_ptr<Person> getPartner() const				// ��, weak_ptr�� �ٷ� ���Ұ��ϰ�, shared_ptr�� �ٲ㼭 �������� �Ѵ�( ��ȯ������������ ���� ���� )
	{
		return _partner.lock();
	}

	const string & getName() const
	{
		return _name;
	}
};

int main()
{
	auto lucy = make_shared<Person>("Lucy");
	auto ricky = make_shared<Person>("Ricky");

	partnerUp(lucy, ricky);						// �� �Ҹ���� ������? -> Person�� shared_ptr�ε� Person class�ȿ� partner shared_ptr�� �����ϱ� ������ ī������ �þ��
												//		�ᱹ , ī���Ͱ� �þ�� �������� ������ �ȵ�	-> weak_ptr��
												// weak_ptr�� �ذ������ ������ ���� -> weak_ptr�� ����Ϸ��� lock�� �ɾ������
	cout << lucy->getPartner()->getName() << endl;

	return 0;
}