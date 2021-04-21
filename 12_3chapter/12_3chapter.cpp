#include <iostream>
using namespace std;

class A
{
public:
    virtual void print(int x) { cout << "A" << endl; }
    //virtual A* getThis(){return this;}
};

class B : public A
{
public:
    void print(int x) override { cout << "B" << endl; }
    //void print1() {cout << "B" << endl;}
    //virtual B* getThis(){return this;}
};

//class C : public B
//{
//public:
//    virtual void print() { cout << "C" << endl; }
//};


int main()
{
    A a;
    B b;
    //C c;

    A& ref = b;
    ref.print(1);

    return 0;
}