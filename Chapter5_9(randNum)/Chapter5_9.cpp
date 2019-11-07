#include < iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>
#include <random>	// C++ 11���� ���� �����Լ�

using namespace std;

unsigned int PRNG()					// pseudo random number generator ����ó�� ���ϻ� ���� ������ �ƴ�
{

	static unsigned int seed = 5523;

	seed = 8253729 * seed + 2396403;
	return seed % 32768;
}

// Ư���� ���� ���̿� ���� �������
int getRandNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);

	return min + static_cast<int> ((max - min + 1)*(rand() *fraction));
}

int main()
{
	srand(5323);	// set seed number ���� ���� ���� PRNG()�Լ��� ���� ������ ���� -> �ٸ� �õ尪���� �����ϰ� �����Ѵ�
	// seed ���ڸ� �ٸ� ���ڸ� �־� �ٸ� �������� ���������ϴ� ������� ��¥�� ����
	srand(static_cast<unsigned int> (std::time(0)));

	for (int count = 1; count <= 100; count++)
	{
		//cout << rand() << "\t";
		cout << rand() % 4 + 5 << '\t';
		cout << getRandNumber(5, 8) << '\t';

		if (count % 5 == 0) cout << endl;
	}

	// random lib���
	cout << "=======================================" << endl;

	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(1, 6);

	for (int count = 1; count <= 20; ++count)
		cout << dice(mersenne) << endl;
	return 0;

}