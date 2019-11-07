#include < iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime>
#include <random>	// C++ 11부터 들어온 랜덤함수

using namespace std;

unsigned int PRNG()					// pseudo random number generator 난수처럼 보일뿐 실제 난수는 아님
{

	static unsigned int seed = 5523;

	seed = 8253729 * seed + 2396403;
	return seed % 32768;
}

// 특정한 정수 사이에 난수 생성방법
int getRandNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);

	return min + static_cast<int> ((max - min + 1)*(rand() *fraction));
}

int main()
{
	srand(5323);	// set seed number 위의 내가 만든 PRNG()함수와 같은 난수가 나옴 -> 다른 시드값으로 랜덤하게 가야한다
	// seed 숫자를 다른 숫자를 넣어 다른 난수값이 나오도록하는 방법으로 날짜를 넣음
	srand(static_cast<unsigned int> (std::time(0)));

	for (int count = 1; count <= 100; count++)
	{
		//cout << rand() << "\t";
		cout << rand() % 4 + 5 << '\t';
		cout << getRandNumber(5, 8) << '\t';

		if (count % 5 == 0) cout << endl;
	}

	// random lib사용
	cout << "=======================================" << endl;

	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dice(1, 6);

	for (int count = 1; count <= 20; ++count)
		cout << dice(mersenne) << endl;
	return 0;

}