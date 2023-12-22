#include <iostream>
using namespace std;


class A{
  public:
  string firstName = "A"; 
};

class B: public A{ //B is a base class of A
  public:
  string lastName= "B";
};

int main(){ 
  cout << ~(34) << endl;
}