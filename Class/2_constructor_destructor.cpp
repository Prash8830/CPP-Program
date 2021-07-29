/*
Constructor - it has same name as a class
            - it has no return type 
            - it is called after object is created whether(dynamic allocation of object, stactic allocation or allocation)
            - if there is no constuctor then complexnoiler automatically create a constructor and puts randoom value in it

Initializer list - after construcor use : then initialize variables
                 - we can initialize some variable there and some varible in constructor body
                 - if there are two constructor one is default and other is parametrized then not using initializer list make double initialization 
                 - performance efficiency

Copy constructor - when = when pointers in class or dynamic allocation in class
                 - need = to copy one pointer to object to another 
                 - without it = defualt copy constructor will be called and copied pointer will point same value
        shallow copy - change in one reflects other - locate same location
        deep copy - change in one don't reflect in other - locate diff location

Destructor - it is called when object is destroyed 
           - it is only one in class
           - it has same name as a class
           - defualt destructor dont handle dynamic allocation garbage collection
*/

#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

class complexno
{
    private:   //access modifier
    int real,imag; //private things are not accessible outside
    int *ptr1;
    public:
    //defuat constructor 
    complexno():real(0),imag(0)  //initializer list
    {
      
    }
    //parametrized constructor
    complexno(int r, int i):imag(i)  //initializer list
    {
        real = r; 
    }
    //copy constructor 
    complexno(const complexno &x)//Note - x must pass by reference oterwise it will cause non terminating recursion
    {
        int val = *(x.ptr1);
        ptr1 = new int(val);
    }
    ~complexno()//destructor
    {
        cout<<"d"<<"\n";//don't use print statments in constr or destru
    }
    void print()
    {
        cout<<real<<"+"<<imag<<"i"<<"\n";
    }
};
 
int main()
{
    fio;
    //constuctor is called in all cases
    complexno a;  //no allocation
    complexno b(10,5); //static allocation
    complexno *c = new complexno(20,40); //dynamic allocation using pointers to object
    complexno d(20,50);
    complexno e;
    //e(d);
    a.print();
    b.print();
    c->print();
    return 0;
}