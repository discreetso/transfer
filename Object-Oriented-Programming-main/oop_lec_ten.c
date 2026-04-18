#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
  string name;      //these are members/fields
  int CNIC;
  int salary;
  int id;

  void sign_in();   //these are called methods
  void sign_out();

  /* class constructor should not have a return type and constructor name same as the class name */
  Employee();             //these are constructors
  Employee(int salary);   //overloaded constructors; having same names, num/types of params diff

  ~Employee();            //destructor
};

void Employee::sign_in() {
  cout << "Signing in the employee " + name << endl;
}

Employee::Employee() {
  cout << "Employee() instance being created ..." << endl;
  salary = 10000;
}

Employee::Employee(int salary) {
  cout << "Employee(int salary) being created ..." << endl;
  this->salary = salary;
}

Employee::~Employee() {
  cout << "Employee instance being destroyes ..." << endl;
}

int main() {
  Employee *e;        //reference variable: type class pointer
  e = new Employee;   //creating an instance which automatically calls constructor

  e->name = "Usman";
  e->sign_in();
  cout << "Salary of the first instance employee: " << e->salary << endl;
  //when you no longer need instance, strongly recommend to free reference variable memory
  delete e;          //before freeing memory, it calls destructor, then free memory

  e = new Employee(70000);    //creaitng an instance which automatically call constructor with param
  cout << "Salary of the secong instance employee: " << e->salary << endl;

  delete e;
  e = NULL;       //fix the "dangling pointer"
  cout << "End of main ..." << endl;

  return 0;
}

