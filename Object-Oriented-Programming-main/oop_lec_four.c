#include <iostream>
using namespace std;

void pointer_test() {
  int x = 25;

  cout << "Value of x: " << x << endl;
  cout << "Value of address of x: " << &x << endl;    //&(ampersand) technical read as: 'address of x'

  int *p;       //integer;write * in place of pointer; read as: integer pointer p
  p = &x;

  cout << "Value of p itself: " << p << endl;
  cout << "Value at address (pointed to by p): " << *p << endl;     //here * is called 'value at' p

  //This *p is called pointer dereferencing
}

void pointer_arr_test() {
  int nums[10];

  for(int i = 0; i < 10; i += 1) {
    nums[i] = i;
  }

  //The starting address of an array is equal to the address of the nums array
  cout << "Value of nums: " << nums << endl;
  cout << "Value of nums[0]: " << nums[0] << endl;

  int *p;
  p = nums;   //as by definition: &nums[0] = nums

  cout << "Value of p: " << p << endl;
  cout << "Value of *p: " << *p << endl;

  cout << "Inc p" << endl;
  p++;        //by convention; we only write p++ when we increment pointer
  cout << "Value of p: " << p << endl;
  cout << "Value of *p: " << *p << endl;

  p = nums;
  cout << "---After resetting the value of p---" << endl;

  for(int i = 0; i < 10; i += 1) {
    cout << "Value of p: " << p << "  ";
    cout << "Value of *p: " << *p << "  ";
    cout << "Inc p" << endl;
    p++;
  }
}

void null_pointer() {       //This is an example of null pointer dereferencing
  int x = 25;
  int *p, *q;

  p = &x;
  q = NULL;

  cout << "Value of p: " << p << endl;
  cout << "Value of *p: " << *p << endl;
  cout << "Value of q: " << q << endl;
  cout << "Value of *q: " << *q << endl;
}

int main() {
  // pointer_test();
  // pointer_arr_test();
  // null_pointer();

  return 0;
}

