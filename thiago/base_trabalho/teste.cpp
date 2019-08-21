// C++ program to explain  
// Single inheritance 
#include <iostream> 
#include <string>
using namespace std; 
  
// base class 
class Vehicle { 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
    void teste(void(*f)(int)){
        f(123);
    }
}; 
  
// sub class derived from two base classes 
class Car: public Vehicle { 
    public:
        Car(){
            
            teste(&this->callback);
        }
        void callback(int msg){
            cout << msg << endl;
        };
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Car obj; 
    return 0; 
} 