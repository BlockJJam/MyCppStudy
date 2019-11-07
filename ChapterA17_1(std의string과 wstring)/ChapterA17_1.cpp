/*
	std::string 과 std::wstring

		using string = basic_string<char, char_traits<char>, allocator<char>>;
		using wstring = basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
*/
#include <iostream>
#include <cstddef>
#include <string>
#include <locale>

using namespace std;

int main()
{
	//basic_string<>의 instantiation인 string과 wstring
	{
		string str;
		wstring wstr;

		wchar_t wc;			//wchar_t : wide character | unicode 에 자주 사용
	}

	const wstring texts[] =
	{
		L"안녕하세요" // korean
		L"Ñá", //Spanish
		L"forêt intérêt", //French
		L"Gesäß", //German
		L"取消波蘇日奇諾", //Chinese
		L"日本人のビット", //Japanese
		L"немного русский", //Russian
		L"ένα κομμάτι της ελληνικής", // Greek
		L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
		L"کمی از ایران ", // Persian (I know it, from 300 movie)
		L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
		L"Но какво, по дяволите, е това?" //Bulgarian
	};

	locale::global(locale(""));
	wcout.imbue(locale());

	for (size_t i = 0; i < 12; i++)
		wcout << texts[i] << endl;

	return 0;
}