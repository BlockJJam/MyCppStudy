# include "Storage.h"

// cpp에서 specialization을 못함, Chapter13_4가 찾지를 못함
template<>
void Storage<double>::print()
{
	std::cout << "double Type ";
	std::cout << std::scientific << _value << std::endl;
}