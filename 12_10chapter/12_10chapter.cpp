#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

int main()
{
    Derived1 d1;
    d1.m_j = 2048;
    Base* base = &d1;

    // dynamic_cast일 때 컴파일 타임에 잘못된 형변환에대한 에러를 잡아줌
    // static_cast는 잘못된 형변환이라 할지라도 어떻게든 작업을 해주려고 함
    //auto* base_to_d1 = dynamic_cast<Derived1*>(base);
    auto* base_to_d1 = dynamic_cast<Derived2*>(base);

    if (base_to_d1 != nullptr)
        cout << base_to_d1->m_name << endl;
    else
        cout << "Failed" << endl;


    return 0;
}