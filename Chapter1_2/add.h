// #pragma once

// 전처리기
#ifndef MY_ADD		// add가 한번 빌드 됐다면 다시 선언하지 말아라 -> 이걸 간단히 쓰는 것이 pragma once
#define MY_ADD

int add(int x, int y)
{
	return x + y;
}

#endif
