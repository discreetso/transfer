#include <iostream>
using namespace std;

struct student {
  int rollno;
  string name;
};

struct node {
  int val;
  node *next;
};

int main() {
  /*below is the one way of making an instance of a student structure, we can also make
  an instance of student structure without giving it the name but can give the values
  to the properties that' the other way which we will discover below   */
  student s1;
  s1.name = "Bilal";
  s1.rollno = 123;

  cout << "--Making student type pointer variable s for s1--" << endl;
  student *s;
  s = &s1;    //this is one way of getting the address

  //one way of getting the value of prop name through pointer variable
  cout << "value of (*s).name: " << (*s).name << endl;
  //second way or a shorthand way of getting the value of prop name through pointer variable
  //"s->" same as "(*s)."
  cout << "value of s->name: " << s->name << endl;

  //other way of creating an instance of student structure
  s = new student;
  /*new operator creates an instance of student structure and return it's address which
  will save in the pointer variable s */
  //can store the value in the prop of new student instance through pointer variable s
  cout << "Address of new instance of student: " << s << endl;
  s->name = "Ali";
  cout << "Value of name in new student instance: " << s->name << endl;

  /*we can delete(in reality, can free) an instance or the chunk in which that instance is
  place by using a keyword 'delete' opposite of keyword 'new'  */
  delete s;


  cout << "Address of new instance of student: " << s << endl;
  /* below line of code will give a segmentation error because what did delete keyword do?
  it free the "chunk" of pointer variable s without the consent whatever stores in that
  chunk it free that chunk from the program an give it to the operatring system now it is
  its property thst's why after deleting, you are trying to access the operating system
  chunk which gives a segmentation error  */
  // cout << "Value of name in new student instance: " << s->name << endl;

/*-------------------------------------------------------------------------*/

  // /* below we are going to connected pieces or concepts we learn before, no new thing only
  // connecting the dots */
  // //node structure created above the main function
  // node *n;
  // n = NULL;
  //
  // //create first node with val 1 and pointer variable value NULL
  // n = new node;
  // n->val = 1;
  // n->next = NULL;
  //
  // //creating second node and stroring it's address in the first node pointer variable next
  // n->next = new node;
  //
  // //putting the value in the second node
  // n->next->val = 5;
  // n->next->next = NULL;
  //
  // //creating third node and stroring it's address in the second node pointer variable next
  // n->next->next = new node;
  //
  // //putting the value in the third node
  // n->next->next->val = 3;
  // n->next->next->next = NULL;
  //
  // cout << "Address of first node: " << n << endl;
  // cout << "Value of the variable val in the first node: " << n->val << endl;
  // cout << "Value of pointer variable next in the first node which stores next node address: " << n->next << endl;

/*------------------------------------------------------------------*/

node *n;    //node type pointer variable n
node *current;    //node type pointer variable current
//create first node, store address in the pointer variable n
n = new node;

//putting the values in the first node
n->val = 10;
n->next = NULL;

//creating the second node, storing it's address in the node type pointer var current
current = new node;


//sharing the address of second node with the first node pointer var next
n->next = current;

/*putting the values in the second node using pointer var current because  it also
own the address second node and it will be easy to understand */
current->val = 20;
current->next = NULL;

/* creating the third node, storing it's address in the node type pointer var
current (ovverriding the address of second node previously stored)*/
current = new node;

//sharing the address of third node with the second node pointer var next
n->next->next = current;

/*putting the values in the third node using pointer var current because  it also
own the address third node and it will be easy to understand */
current->val = 30;
current->next = NULL;

cout << "Address of first node: " << n << endl;
cout << "Value of the variable val in the first node: " << n->val << endl;
cout << "Value of pointer variable next in the first node which stores next node address: " << n->next << endl;
cout << "Value of the variable val in the second node: " << n->next->val << endl;
  return 0;
}

