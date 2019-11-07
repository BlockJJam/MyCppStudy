#include <iostream>				// "<>"와 "큰따움표" 와의 차이는 표준과 표준이 아닌 차이 
#include "add.h"
#include "doSomething.h"
// 객체지향 가면 클래스 파일을 쪼개고 메인과 같이 안쓴다
// 헤더에 있는 소스파일이 없으면 링크에러가 뜨는데 더블클릭해도 그쪽으로 안간다
// 헤더 가드는 (pragma once) 중복이 있으면 한번만 선언정의해라
using namespace std;

int main()
{
	doSomething();
	return 0;
}