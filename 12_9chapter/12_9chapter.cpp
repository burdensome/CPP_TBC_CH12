#include <iostream>
#include <vector>
#include <functional>

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

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

void doSomething(Base& b)
{
    b.print();
}

int main()
{
    Base b;
    Derived d;
    //Base& b = d;

    //doSomething(d);
    //b.print();

    // vector는 reference를 바로 사용 할 수 없다.
    // std::vector<Base&> my_vec; 같이 사용이 안됨. 그래서
    // refereence_wrapper를 사용하는 것이다 다만 데이터를 가져올 때 get()을 사용함!
    std::vector<std::reference_wrapper<Base>> my_vec;
    my_vec.push_back(b);
    my_vec.push_back(d);

    for (auto& ele : my_vec)
        ele.get().print();

    return 0;
}