//namespaces  (less important, studying for the sake of completeness)
#include <iostream>
#include <string>
//namespaces allow us to create subscopes within
//these can be functions, variables or classes within them

namespace first {
  int var = 5;
}
namespace second {
  double var = 3.1415;
}

int main() {
  //with using namespaces
  using namespace std;
  using namespace first;      //if you add both, you get an error
  // using namespace second;

  cout << var << endl;
  cout << second::var << endl;

  //without using namespaces
  // std::cout << first::var << std::endl;
  // std::cout << second::var << std::endl;
  return 0;
}


//function template (almost not used by professional programmers)
#include <iostream>
#include <string>
using namespace std;

template <class T>
T find_max(T a, T b) {
  T result;
  result = (a > b) ? a : b;
  return result;
}

int main() {
  int x, y, k;
  x = 25;
  y = 21;
  k = find_max<int>(x, y);
  cout << "result of integer maximization: " << k << endl;

  string a, b, j;
  a = "Usman";
  b = "Ali";
  j = find_max<string>(a, b);
  cout << "result of string maximization: " << j << endl;
}




/* class template (generic)(vey important! mostly used by professional programmers)
    of LIFO to make it usable for other data types */

#include <iostream>
#include <string>
using namespace std;

template <class T>
class List {
  struct node {
    T val;
    node *next;
  };

  node *head, *last;
  void delete_after_node(node *current);

public:
  List();
  void push(T val);
  T pop();
  void print_list();
};

template <class T>
List<T>::List() {
  head = last = NULL;
}

template <class T>
void List<T>::push(T val) {
  node *temp = new node;
  temp->val = val;
  temp->next = NULL;

  if(last == NULL) {      //need this when list is empty
    head = temp;
    last = temp;
  } else {                //for all other cases
    last->next = temp;
    last = last->next;
  }
}

template <class T>
T List<T>::pop() {
  T val;
  if(head->next == NULL) {
    val = last->val;    //saving val for later use
    delete head;        //deleting head

    head = NULL;        //nothing left in list now
    last = NULL;
  } else {              //for all other cases
    val = last->val;    //saving val for later use
    node *current = head;

    while(current->next != last) {
      current = current->next;
    }

    //node current is just before last, so delete last
    delete_after_node(current);
    last = current;
  }
  return val;         //now return the value we send later
}

template <class T>
void List<T>::delete_after_node(node *current) {
  node *temp = current->next;
  current->next = current->next->next;
  delete temp;
}

template <class T>
void List<T>::print_list() {
  node *current = head;

  cout << "[ ";
  while (current != NULL) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << "]" << endl;
}

int main() {
  List<int> l;
  l.push(5);
  l.push(15);
  l.push(21);
  l.pop();
  l.print_list();
}

