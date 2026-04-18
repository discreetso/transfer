#include <iostream>
#include <vector>
using namespace std;

void output_vector_values(vector<int> v);
void reverse_output_vector_values(vector<int> v);

int main() {
  vector<int> marks;                        //a vector is essentially python's list

  for(int i = 1; i <= 5; i++) {             //is append
    marks.push_back(i * 10);
  }

  //alternatively
  // vector<int> marks{10, 20, 30, 40, 50};

  output_vector_values(marks);
  reverse_output_vector_values(marks);

  //let's remove a value from a specific position
  auto it = marks.begin();
  marks.erase(it + 2);

  //output values after erase
  output_vector_values(marks);
}

void output_vector_values(vector<int> v) {
  //use v.begin() to get a pointer at the start
  //(but this isn't the int *)...it's a really weird pointer called "iterator"
  //we don't know how to declare that. So, let's use the auto keyword here

  cout << "[";
  for(auto i = v.begin(); i != v.end(); i++) {
    cout << *i << " ";
  }
  cout << "]" << endl;

  //alternatively
  // cout << "[";
  // for(int x: v) {            //sort of like the for loop in python
  //   cout << x << " ";
  // }
  // cout << "]" << endl;
}

void reverse_output_vector_values(vector<int> v) {
  //just change the "begin()" with "rbegin()" & "end()" with "rend()"

  cout << "[";
  for(auto i = v.rbegin(); i != v.rend(); i++) {
    cout << *i << " ";
  }
  cout << "]" << endl;
}

