#include<iostream>
using namespace std;

class A{
 public:
 virtual void show(int i=1){ cout<<"A is"<<i<<endl; }

};

class B:public A{
 public:
 virtual void show(int i=2){ cout<<"B is "<<i<<endl; }

};


int main(){
  A aa,*b,*c;
  B bb;
  bb.show(); 
  b=&bb;
  b->show();
}
