// short circuiting, cout and return keywords, function prototype, global and local scope

#include <iostream>
#include <stdio.h>
using namespace std;

int out(int x);

int main() {
    int final_val = out(0) && out(1);
    cout << "Final value: " << final_val << endl;
    return 0;
}

int out(int x) {
    cout << "- called with vaue " << x << endl;
    return x;
}
