// to create a field or method which is only specific to the parent class we use 'static'.

#include <iostream>
#include <string>
using namespace std;

class Student {
  int id;
  static int next_id;

public:
  static int next_user_id();
  Student();                // constructor
  int get_id();
};

int Student::next_id = 0;       // initialize the static variable here

int Student::next_user_id() {
  next_id++;
  return next_id;
}

Student::Student() {
  id = Student::next_user_id();
}

int Student::get_id() {
  return id;
}

int main() {
  Student s;
  cout << "ID for s: " << s.get_id() << endl;

  Student v;
  cout << "ID for v: " << v.get_id() << endl;
  return 0;
}
/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
// Static function locals
// static variable of a function called "static function locals"

#include <iostream>
#include <string>
using namespace std;

int fib(int n);

int main() {
  fib(3);
  cout << "Total count: " << fib(-1) << endl;

  return 0;
}

int fib(int n) {
  static int count = 0;
  //hack: just for retruning the count
  if (n == -1) {
    return count;
  }
  count += 1;   //increment call count

  if(n <= 1) {
    return n;
  } else {
    return fib(n - 2) + fib(n - 1);
  }
}

/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */

//Setters and Getters functions
// These functions sets and gets the value of a private member for us.

#include <iostream>
#include <string>
using namespace std;

class Employee {
  int pay_rate;

public:
  Employee();

  void set_pay_rate(int pay_rate);
  int get_pay_rate();
};

Employee::Employee() {
  pay_rate = 14;
}

void Employee::set_pay_rate(int pay_rate) {
  if(pay_rate > 14) {
    this->pay_rate = pay_rate;
  } else {
    cout << "Pay rate " << pay_rate << " not acceptable, not setting ..." << endl;
  }
}

int Employee::get_pay_rate() {
  return pay_rate;
}

int main() {
  Employee a;
  // a.pay_rate = 15;

  cout << "Constructor initialized value: " << a.get_pay_rate() << endl;

  a.set_pay_rate(15);
  cout << "Pay rate: " << a.get_pay_rate() << endl;
  a.set_pay_rate(13);

}

/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
//Access modifiers or Access specifiers: public, private and protected

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
  int pay_rate;

public:
  Employee();

  void set_pay_rate(int pay_rate);
  int get_pay_rate();
};

Employee::Employee() {
  pay_rate = 14;
}

void Employee::set_pay_rate(int pay_rate) {
  if(pay_rate > 14) {
    this->pay_rate = pay_rate;
  } else {
    cout << "Pay rate " << pay_rate << " not acceptable, not setting ..." << endl;
  }
}

int Employee::get_pay_rate() {
  return pay_rate;
}

//child class FacultyMember
class FacultyMember: public Employee {
public:
  FacultyMember();
  void set_pay_rate(int pay_rate);
};

FacultyMember::FacultyMember() {
  pay_rate = 25;
}

void FacultyMember::set_pay_rate(int pay_rate) {
  if(pay_rate > 25) {
    this->pay_rate = pay_rate;
  } else {
    cout << "Pay rate " << pay_rate << " not acceptable, not setting ..." << endl;
  }
}

int main() {
  Employee a;
  a.pay_rate = 15;
  
  cout << "Constructor initialized value: " << a.get_pay_rate() << endl;
  
  a.set_pay_rate(15);
  cout << "Pay rate: " << a.get_pay_rate() << endl;
  a.set_pay_rate(13);

  FacultyMember fm;

  fm.set_pay_rate(26);
  cout << "Pay rate: " << fm.get_pay_rate() << endl;
  fm.set_pay_rate(23);
}

/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
//friend function example

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
  int pay_rate;

public:
  Employee();

  void set_pay_rate(int pay_rate);
  int get_pay_rate();
  //declaring friend function
  friend void access_pay_rate_directly(Employee e);
};

Employee::Employee() {
  pay_rate = 14;
}

void Employee::set_pay_rate(int pay_rate) {
  if(pay_rate > 14) {
    this->pay_rate = pay_rate;
  } else {
    cout << "Pay rate " << pay_rate << " not acceptable, not setting ..." << endl;
  }
}

int Employee::get_pay_rate() {
  return pay_rate;
}

//friend function
void access_pay_rate_directly(Employee e) {
  cout << "I am a friend function, I'm going to tear up the abstraction ..." << endl;
  cout << "pay_rate: " << e.pay_rate << endl;
}

//child class FacultyMember
class FacultyMember: public Employee {
public:
  FacultyMember();
  void set_pay_rate(int pay_rate);
};

FacultyMember::FacultyMember() {
  pay_rate = 25;
}

void FacultyMember::set_pay_rate(int pay_rate) {
  if(pay_rate > 25) {
    this->pay_rate = pay_rate;
  } else {
    cout << "Pay rate " << pay_rate << " not acceptable, not setting ..." << endl;
  }
}

int main() {
  Employee a;
  a.pay_rate = 15;
  
  cout << "Constructor initialized value: " << a.get_pay_rate() << endl;
  
  a.set_pay_rate(15);
  cout << "Pay rate: " << a.get_pay_rate() << endl;
  a.set_pay_rate(13);

  access_pay_rate_directly(a);

  FacultyMember fm;
  
  fm.set_pay_rate(26);
  cout << "Pay rate: " << fm.get_pay_rate() << endl;
  fm.set_pay_rate(23);
}
