# include "Storage.h"

// cpp���� specialization�� ����, Chapter13_4�� ã���� ����
template<>
void Storage<double>::print()
{
	std::cout << "double Type ";
	std::cout << std::scientific << _value << std::endl;
}