#ifndef BASIC_H
#define BASIC_H
#include <iostream>
#include <memory>


class A
{
public:
    A(int val):m_value{val}{std::cout<<"A()\n";}
    ~A(){std::cout << "~A()\n";}

    int operator+(int val){m_value += val; return m_value;}
    int operator+=(int val){return operator+(val);}
    int operator*(){return m_value;}
    int value()const{return m_value;}

private:
    int m_value;

};

void funPointer();
void funAutoPointer();
void funUniquePointer();
void sharedPointer();
void funWeakPointer();

std::ostream& operator<<(std::ostream& out, const A & a);
std::ostream& operator<<(std::ostream& out, const A* a);
std::ostream& operator<<(std::ostream& out, const std::auto_ptr<A>& ptr);
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<A>& ptr);
std::ostream& operator<<(std::ostream& out, const std::unique_ptr<A>& ptr);
std::ostream& operator<<(std::ostream& out, const std::weak_ptr<A>& ptr);

#endif //BASIC_H