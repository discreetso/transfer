#include <iostream>
using namespace std;

#define SIZE 5    //preprocessor

#define ABS(a) ((a) < 0 ? -(a) : a)     //function look-a-like preprocessor called macros

#define INCLUDE_INVENTORY_MODULE        //switch (also called flag); comment it see what happens

#ifdef INCLUDE_INVENTORY_MODULE
  void show_inventory() {
    cout << "Showing inventory ..." << endl;
  }
#endif

int main() {
  for(int i = 0; i < SIZE; i += 1) {
    cout << i << endl;
  }
  cout << "SIZE" << endl;

  cout << "Absolute value of -5: " << ABS(-5) << endl;

  #ifdef INCLUDE_INVENTORY_MODULE
      show_inventory();
  #endif

  return 0;
}

