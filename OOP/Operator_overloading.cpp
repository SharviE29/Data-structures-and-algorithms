//This program is for adding two rational numbers using the concept of operator overloading

#include<iostream>
using namespace std;
class Rational
{
    private:
    int p;
    int q;
    public:
    Rational() //default constructor is created initially
    {
        p=1;
        q=1;
    }
    Rational(int p,int q)// parametrised constructor
    {
        this->p=p;//using this pointer is used for referring members of the current object
        this->q=q;
    }
    Rational(Rational &r)//copy constructor//This will take the object by reference as a parameter to copy the values or parameters in a different object of the same class
    {
        this->p=r.p;
        this->q=r.q;
    }
    int getP()
    {
        return p;
    }
    int getq()
    {
        return q;
    }
    void setQ(int q)
    {
        this->q=q;
    }
    void setp(int p)
    {
        this->p=p;
    }
    Rational operator+(Rational r)//overloading the + operator for performing addition operations on objects
    {
        Rational t;//creating a temporary variable to store the value of the sum
        t.p=this->p*r.q+ this->q*r.p;
        t.q=this->q*r.q;
        return t;
    }
    friend ostream &operator<<(ostream &os,Rational &r);//ovreloading the insertion operator //hence defined a friend function
};
ostream &operator<<(ostream &os,Rational &r)//the two parameters taken for overloading the insertion operator are the object itself, and the object created from the ostream class from which cout is an object
{
    os<<r.p<<"/"<<r.q;
    return os;
}
int main()
{
  Rational r1(3,4),r2(2,5),r3;    
  r3=r1+r2;
  cout<<"Sum of "<<r1<<" and "<<r2<<" is "<<r3<<endl;
}
