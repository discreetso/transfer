#include <iostream>
using namespace std;

//create a node structure
struct node {
  int val;
  node *next;
};

//will the return a node pointer value that's why fnx type is node pointer
node* create_node(node *current, int new_node_value) {
  node *n;
  n = new node;

  n->val = new_node_value;
  n->next = NULL;

  //link the new node to the current node's next pointer
  current->next = n;
  return n;
}

//fnx to print all values in the linked list starting from head
void output_list(node *head) {
  node *current = head;

  cout << "[";
  while(current != NULL) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << "]" << endl;
}

//sum all the elements of the list
void sum_list(node *head) {
  node *current = head;
  int sum = 0;

  while(current != NULL) {
    sum = sum + current->val;
    current = current->next;
  }
  cout << "Sum of all the elements of the list: " << sum << endl;
}

//fnx to delete the node imidiately after the given node
void delete_after_node(node *current) {
  node *temp = current->next;           //store pointer to node to be deleted
  current->next = current->next->next;  //bypass the node to be deleted
  delete temp;                          //free memory of the deleted node
}

int main() {
  //creating a head node()
  node *head;
  head = new node;    //creating head node

  //putting values in the head node
  head->val = 2;
  head->next = NULL;

  //create a node pointer current, pointing to the same node, head is pointing
  node *current = head;

  //calling the create_node fnx which creates node and link it to the previous node
  current = create_node(current, 17);
  current = create_node(current, 54);
  current = create_node(current, 31);

  output_list(head);
  sum_list(head);

  /* assign this to print the val which is going to be deleted instead of that we can write
  head->next->val */
  current = head->next;
  cout << "Going to delete: " << current->val << endl;

  //delete the node after head
  delete_after_node(head);
  output_list(head);
  sum_list(head);

  return 0;
}

