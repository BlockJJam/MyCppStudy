/* 
	자료형추론 auto 와 decltype 
*/

#include <iostream>
#include <vector>
#include <algorithm> //std::min

// Reference : http://thbecker.net/article/auto_and_decltype/section_01.html

using namespace std;
class Example
{
public:
	void ex1()
	{
		vector<int> vec;

		for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
			cout << *itr;

		for (auto itr = vec.begin(); itr != vec.end() ;itr++)
			cout << *itr;

		for (auto itr : vec)
			cout << itr;
	}
	void ex2()
	{
		int x = int();
		auto auto_x = x;

		const int &crx = x;
		auto auto_crx1 = crx;	// const &(ref)를 다 떼고 생각한다
		const auto& auto_crx2 = crx;

		volatile int vx = 1024;	// 값이 자주바뀌기 때문에 최적화에 빼달라는 의미?

		auto avx = vx;

		volatile auto vavx = vx;
	}

	//template <class T>
	//void func_ex3(T arg)
	//{}

	 template<class T>
	void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int &crx = 123;

		func_ex3(crx);

	}
	
	void ex4()
	{
		const int c = 0;
		auto &rc = c;		// reference로 가져오는 것이 const라면 const int로 선언된다
	}

	void ex5()
	{
		int i = 42;
		auto && ri_1 = i;	// l-value( 즉 수정됨 )
		auto && ri_2 = 42;	// r-value
	}

	void ex6()
	{
		int x = 42;
		const int * p1 = &x;
		auto p2 = p1;		// const int
	}

	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		auto prod1 = lhs * rhs;
		//typedef typeof(lhs * rhs) product_type; // C++11 이전 '몇몇' compilers
		typedef decltype(lhs*rhs) product_type; // 이전에는 이렇게 타입을 정의 해주었다

		product_type prod2 = lhs * rhs;

		decltype(lhs*rhs) prod3 = lhs * rhs;	// 위 두줄과 같은 표현
	}

	template<typename T, typename S>
	auto func_ex8(T lhs, S rhs) -> decltype(lhs*rhs)
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 'a');
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S *p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;	// p->m_x의 값은 수정 X이나, auto e에 복사하면 사용 가능

		typedef decltype(x)		 x_type;
		typedef decltype(cx)	 cx_type;
		typedef decltype(crx)	 crx_type;
		typedef decltype(p->m_x) m_x_type;			// 'declared' type
		
		typedef decltype((x)) x_with_parents_type;	// add references to lvalues, ()가 하나 더붙으면 &가 붙음
		typedef decltype((cx)) cx_with_parents_type;
		typedef decltype((crx)) crx_with_parents_type;	// 원래 &가 붙어있다면 그대로 이용
		typedef decltype((p->m_x)) m_w_with_parents_type; // const가 붙는다
	}

	const S foo()
	{
		return S();
	}
	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		vector <int> vect ={42, 43};

		auto a = foo();
		typedef decltype(foo()) foo_type;

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;

		auto itr = vect.begin();
		typedef decltype(vect.begin()) iterator_type;

		auto first_element = vect[0];
		decltype(vect[1]) second_element = vect[1];	// vect[1] 의 return type 이 int & 이다
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 3.27;

		typedef decltype(x*y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx*cy) prod_cxcy_type;	// result is prvalue
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type;	// result is lvalue. & is added;
		auto c = d1 < d2 ? d1 : d2;						// auto 는 double ,not &

		typedef decltype(x < d2 ? x : d2) cond_type_mixed;// promotion of x to double, 섞이면 double , not &
		auto d = x < d2 ? x : d2;

		// auto d = std::min(x,dbl); // error(서로 다른 타입이면)
	}
	// min 에러안나게 구현해보자
	template<typename T, typename S> 
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)			// decltype의 괄호안에서는 수행되지 않고 추론만 한다, decltype에서 x,y가 같은 타입이면 &이 붙는다
	{
		return x < y ? x : y;
	}

	template<typename T, typename S>
	auto fpmin(T x, S y)->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double d = 45.1;
		auto a = std::min(static_cast<double>(i), d);

		int &j = i;

		/*typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1;
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type1;
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type1;*/
	}

	void ex13()
	{
		std::vector<int> vect;
		typedef decltype(vect[0]) integer;		// 실제로 vect[0]이 수행하지 않아서 error가 아님
	}
	
	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer;   // nest type
	}

	void ex15()
	{
		auto lambda = []() { return 45; };
		decltype(lambda) lambda2(lambda);
		decltype((lambda)) lambda3(lambda);
		
		cout << "Lambda functions" << endl;
		cout << &lambda << " " << &lambda2 << endl;			// 주소가 다름
		cout << &lambda << " " << &lambda3 << endl;			// &라 주소가 같음
	}

	void ex16()
	{
		// generic lambda
		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};
		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
	}
};
int main()
{
	Example ex;

	return 0;
}