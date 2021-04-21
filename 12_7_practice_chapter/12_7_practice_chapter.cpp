#include <iostream>
#include <string>
using namespace std;

class IErrorLog // Interface�� �տ� I�� �տ� ���̴°� ����
{
public:
    virtual bool reportError(const char* errorMessage) = 0;

    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << errorMessage << endl;
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << errorMessage << endl;
        cout << "Printing error to a console" << endl;
        return true;
    }
};

void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);
    doSomething(console_log);

    return 0;
}