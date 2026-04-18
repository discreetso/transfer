#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
  string name;
  int CNIC;

  void sign_in();
  void promote();
};

void Employee::sign_in() {
  cout << "Signed In__Welcome " + name << endl;
}

int main() {
  Employee e1;      //e1 is an instance or object of class Employee
  e1.name = "Ali";
  e1.sign_in();

  Employee *e;      //e is a reference variable of a class(Employee) pointer
  e = &e1;
  cout << "One way of getting the address: " << e << endl;

  e = new Employee;
  e->name = "Usman";
  e->sign_in();
  cout << "Address of new Employee: " << e << endl;

  return 0;
}

