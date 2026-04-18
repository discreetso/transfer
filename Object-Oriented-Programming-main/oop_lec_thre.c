#include <iostream>
using namespace std;

struct student {
  int rollnum;
  float marks;
};

void array_test() {
  int a[5];
  cout << "Before assignment:" << endl;
  for (int i = 0; i < 5; i += 1){
    cout << a[i] << "  ";
  }
  cout << endl;

  cout << "After assignment:" << endl;
  for(int i = 0; i < 5; i += 1) {
    a[i] = i*i;
    cout << a[i] << "  ";
  }
  cout << endl;
}

void char_test() {
  string a = "Hello";
  cout << a << endl;

  cout << "a[5]: " << a[5] << endl;

  if (a[5] == '\0') {
    cout << "a[5] is a Null terminator." << endl;
  }

  int counter = 0;
  for (int i = 0; i < 5; i += 1) {
    if(a[i] == 'l') {
      counter += 1;
    }
  }
  cout << counter << endl;

  string name = "Mudasser";
  cout << name << endl;

  cout << "Is Mudasser empty? " << name.empty() << endl;

}

void struct_test() {
  student s1, s2;
  s1.marks = 87.5;
  s2.marks = 90.1;

  cout << "student 1 has marks " << s1.marks << endl;
  cout << "student 2 has marks " << s2.marks << endl;

  student s[5];
  s[0].marks = 59.5;
  cout << "Student s[0] has marks " << s[0].marks << endl;
}

void two_dim_arr() {
  int a[2][3];

  for(int i = 0; i < 2; i += 1) {
    for(int j = 0; j < 3; j += 1) {
      cout << a[i][j] << "  ";
    }
    cout << endl;
  }

  int val = 1;
  for(int i = 0; i < 2; i += 1) {
    for(int j = 0; j < 3; j += 1) {
      a[i][j] = val;
      val += 1;
    }
  }

  for(int i = 0; i < 2; i += 1) {
    for(int j = 0; j < 3; j += 1) {
      cout << a[i][j] << "  ";
    }
    cout << endl;
  }
}

int main() {
  // array_test();
  // char_test();
  // struct_test();
  // two_dim_arr();
  return 0;
}

