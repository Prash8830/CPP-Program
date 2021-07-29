/*

class - datatype ;  object - variable 

Encapsulation - It is idea to bundle data and related functions together

Abstraction - Hiding private details and only showing public interface

Inheritance - Putting common code to parent class and inheriting it by children class

Polymorphism - Same name with differnt functionalities // Two types - STATIC AND DYNAMIC

*/

#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

class comp
{
    private:   //access modifiers
    int real,imag; //private things are not accessible outside

    public:
    comp(int r, int i)       //constructor
    {
        real = r;
        imag = i; 
    }
    void print()
    {
        cout<<real<<"+"<<imag<<"i"<<"\n";
    }
};
 
int main()
{
    fio;
    
    comp a(5,10);  
    comp b(10,5);
    a.print();
    b.print();
    
    return 0;
}