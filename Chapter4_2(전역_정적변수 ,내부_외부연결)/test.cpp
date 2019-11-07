#include <iostream>
#include "MyHeader.h"

extern int a = 123;
void doSomething()
{
	using namespace std;
	cout << "In test.cpp " << Constants::pi << " " << &Constants::pi << endl;
}