#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {}

public:
    string getName() { return m_name; }

    virtual void speak() const = 0; // pure virtual function

    /*virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }*/
};

//void Animal::speak() const  // the body of  the pure virtual function
//{
//    cout << m_name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        : Animal(name)
    {}

    virtual void speak() const
    {
        cout << m_name << " Moooo " << endl;
    }
};


int main()
{
    /*Animal ani("HI");
    ani*/
    
    Cow cow("Hello");
    cow.speak();

    return 0;
}