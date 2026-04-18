//use case or case study of OOP concepts, also power of abstraction which we mainly get by classes

#include <iostream>
#include <string>
using namespace std;

#define SIZE 5                 //change the value of macro size and see what happens
void pause();

class Queue {
private:
  int q[SIZE];
  int in, out;
  bool is_empty, is_full;
  //increment method
  void inc(int *arrow);

public:
  Queue();
  void enqueue(int val);
  int dequeue();
  void print_queue();
};

Queue::Queue() {
  for(int i = 0; i < SIZE; i++) {
    q[i] = 0;
  }

  in = out = 0;
  is_empty = true;
  is_full = false;
}

void Queue::inc(int *arrow) {
  if(*arrow + 1 == SIZE) {
    *arrow = 0;
  } else {
    *arrow += 1;
  }
}

void Queue::enqueue(int val) {
  if(is_full) {
    throw"Queue full, cannot enqueue";
    return;
  }
  //put val where in is & inc in
  q[in] = val;
  inc(&in);

  //see if the queue is full
  if(in == out) {
    is_full = true;
  }
  is_empty = false;
}

int Queue::dequeue() {
  if(is_empty) {
    throw"Queue is empty, cannot dequeue";
  }

  //take val from, where out is & inc out
  int ret = q[out];
  inc(&out);

  //see if the queue gets empty
  if(in == out) {
    is_empty = true;
  }
  is_full = false;

  return ret;
}

void Queue:: print_queue() {
  cout << "[\t";
  for(int i = 0; i < SIZE; i++) {
    cout << q[i] << "\t";
  }
  cout << "]" << endl;

  cout << " \t";
  for(int i = 0; i < SIZE; i++) {
    cout << i << "\t";
  }
  cout << " " << endl;

  cout << " ";
  for(int i = 0; i <= in; i++) {
    cout << "\t";
  }
  cout << "^in" << endl;

  cout << " ";
  for(int i = 0; i <= out; i++) {
    cout << "\t";
  }
  cout << "^out" << endl;

  pause();
}

int main() {
  try {
    Queue que;
    que.print_queue();

    que.enqueue(5);
    que.print_queue();

    que.enqueue(11);
    que.print_queue();

    que.enqueue(22);
    que.print_queue();

    que.enqueue(33);
    que.print_queue();

    que.enqueue(44);
    que.print_queue();

    // que.enqueue(55);                //uncomment & then change is_full

    //let's dequeue
    cout << "Now dequeue ..." << endl;

    cout << "Got val: " << que.dequeue() << endl;
    que.print_queue();

    cout << "Got val: " << que.dequeue() << endl;
    que.print_queue();

    cout << "Got val: " << que.dequeue() << endl;
    que.print_queue();

    cout << "Got val: " << que.dequeue() << endl;
    que.print_queue();

    cout << "Got val: " << que.dequeue() << endl;
    que.print_queue();
  } catch(const char *msg) {
    cout << msg << endl;
  }
  return 0;
}

void pause() {
  getchar();
}

