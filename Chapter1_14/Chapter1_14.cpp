// chapter1_14.cpp : Defines the entry point for the console 

#include <iostream>
#include <algorithm>

using namespace std;

#define MY_NUMBER 333				// ��ũ�� : ��ü��
#define MAX(a,b) (((a)>(b)) ? (a) :(b))
#define LIKE_APPLE				// define�� ���� : ���� �ȿ���

void doSomething();

int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(1+3, 2) << endl; // ���� ���� �̷��� ���Ѵ�
	cout << max(4, 2) << endl;

	doSomething();
	return 0;
}