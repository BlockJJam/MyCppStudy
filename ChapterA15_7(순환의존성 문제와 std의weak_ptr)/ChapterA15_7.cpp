/*
	순환의존성 문제, weak_ptr
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

	const shared_ptr<Person> getPartner() const				// 즉, weak_ptr은 바로 사용불가하고, shared_ptr로 바꿔서 사용해줘야 한다( 순환의존성문제를 깨기 위해 )
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

	partnerUp(lucy, ricky);						// 왜 소멸되지 않을까? -> Person이 shared_ptr인데 Person class안에 partner shared_ptr이 존재하기 때문에 카운팅이 늘어난다
												//		결국 , 카운터가 늘어나서 소유권이 해제가 안됨	-> weak_ptr로
												// weak_ptr로 해결되지만 단점이 존재 -> weak_ptr를 사용하려면 lock을 걸어줘야함
	cout << lucy->getPartner()->getName() << endl;

	return 0;
}