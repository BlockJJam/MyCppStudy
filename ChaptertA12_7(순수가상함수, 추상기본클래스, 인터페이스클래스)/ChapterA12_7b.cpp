#include <iostream>
#include <string>

using namespace std;

class IErrorLog														// interface�� Ŭ���� �տ� I�� �ٿ��ش�
{
public:
	virtual bool reportError(const char * errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char * errorMessage) override
	{
		cout << errorMessage << " : Writing error to a File" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char * errorMessage) override
	{
		cout << errorMessage << " : Printing error to a Console" << endl;
		return true;
	}
};

void doSomething(IErrorLog & log)
{
	log.reportError("Runtime error !! ");
}


int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}