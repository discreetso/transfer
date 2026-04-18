#include <iostream>
using namespace std;

void print_move(int disk, char from_rod, char to_rod) {
  cout << "Move disk " << disk << " from rod " << from_rod << " to rod " << to_rod << endl;
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
  if(n == 1) {
    //just the smallest disk, can be moved directly anywhere
    print_move(n, from_rod, to_rod);
    return;
  }

  //move all-minus-largest from FROM to AUX (using TO as extra)
  move_disk(n-1, from_rod, aux_rod, to_rod);

  //move largest disk
  print_move(n, from_rod, to_rod);

  //move all-minus-largest from AUX (where we left them) to TO (using FROM as extra)
  move_disk(n-1, aux_rod, to_rod, from_rod);
}

int main() {
  int n = 3;                    //num of disks
  move_disk(n, 'A', 'C', 'B');  //A, B and C are names of rods
  return 0;
}

// tell me what is the only purpose of this lune of code that it only moves disk 1 from rod A to rod B using C as auxiliary is it right

