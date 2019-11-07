/* 
	자료형 하나 선언만으로 많은 것을 표현하기 어려우니 사용자 정의 자료형모음집을 사용하자 => struct(구조체)
	매개변수로 여러 자료형을 다 넣을 필요도 없고, 일일이 함수 안에 다 정의하고 너무 더러워진다
*/
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	double height= 123.0;
	float weight = 20.0;
	int age= 12;
	string name= "Mr.Joo";

	// 구조체 안에 두기
	void printPersonInfo()
	{
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}

};

struct Family
{
	Person me, mom, dad;
};

// 함수가 struct를 return할 수도 있다
Person getMe()
{
	Person me{ 180.4,40.5,20,"JJM" };
	return me;
}

Person getMom()
{
	Person mom{ 167.4,40.5,20,"KHY" };
	return mom;
}

Person getDad()
{
	Person dad{ 182.4,40.5,20,"JMK" };
	return dad;
}
//구조체 밖에 두기
//void printPerson(Person ps)
//{
//	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
//	cout << endl;
//}

// 조금더 어려운 예제
struct Employee										// 2 + (2) + 4 + 8= 14 (16) byte ( id가 2 -> 4byte로 잡힌다 ) -> padding
{
	short	id;										// 2 byte
	int		age;									// 4 byte
	double	wage;									// 8 byte
};

int main()
{

	Person me;
	me.printPersonInfo();
	// 멤버가 복잡해지면 operator가 의도대로 작동이 안될 수 있다 조심! (below)
	Person me2 = getMe();
	me2.printPersonInfo();

	//employee
	Employee emp1;
	
	cout << sizeof(Employee) << endl;				// 14byte (X) -> 16byte (0) 메모리구조에 컴파일러가 맞춤

	return 0;
}