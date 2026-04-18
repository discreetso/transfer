#include <iostream>
#include <string>
using namespace std;

//Adobe developers
class Plugin {
public:
  virtual void apply_filter(int img[5][5]);
};

void Plugin::apply_filter(int img[5][5]) {
  cout << "Plugin method called ... can't do anything" << endl;
}

//3rd party
class MakeItBlack: public Plugin {
public:
  //overridding
  void apply_filter(int img[5][5]);
};

void MakeItBlack::apply_filter(int img[5][5]) {
  for(int i = 0; i < 5; i += 1) {
    for(int j = 0; j < 5; j += 1) {
      img[i][j] = 0;
    }
  }
}

class MakeItWhite: public Plugin {
public:
  //overridding
  void apply_filter(int img[5][5]);
};

void MakeItWhite::apply_filter(int img[5][5]) {
  for(int i = 0; i < 5; i += 1) {
    for(int j = 0; j < 5; j += 1) {
      img[i][j] = 255;
    }
  }
}

//xxxxxx classes end here xxxxxx

//As the main func written by Adobe dev so that we can't hard code in the main
Plugin * get_filter();
void init_img_arr(int a[5][5]);     //image array initialization function
void output_img_arr(int a[5][5]);   //image array output function

int main() {
  int a[5][5];
  //
  init_img_arr(a);
  cout << "After initializing image array: " << endl;
  output_img_arr(a);

  //hardcoded MakeItBlack and MakeItWhite
  // Plugin p;
  // cout << "Calling Plugin instance method ..." << endl;
  // p.apply_filter(a);
  //
  // MakeItBlack mib;
  // mib.apply_filter(a);
  // cout << "After calling MakeItBlack instance method ..." << endl;
  // output_img_arr(a);
  //
  // MakeItWhite miw;
  // miw.apply_filter(a);
  // cout << "After calling MakeItWhite instance method ..." << endl;
  // output_img_arr(a);

  //other way (POLYMORPHISM)
  Plugin *p;                //parent pointer p can hold it's own and it's child class instances addres
  p = get_filter();         //This will return the address of the specific child Plugin
  p->apply_filter(a);     //as parent apply_filter method virtual, ref.var call to which p is pointing
  output_img_arr(a);
}

//function written by 4th party (not hardcoded written outside of the main)
Plugin * get_filter() {
  string filter_name = "MIB";
  Plugin *p;
  if(filter_name == "MIB") {
    p = new MakeItBlack;
  } else {
    p = new MakeItWhite;
  }
  return p;
}

//helper functions
void init_img_arr(int a[5][5]) {
  int val = 10;
  for(int i = 0; i < 5; i += 1) {
    for(int j = 0; j < 5; j += 1) {
      a[i][j] = val;
      val += 1;
    }
  }
}

void output_img_arr(int a[5][5]) {
  for(int i = 0; i < 5; i += 1) {
    for(int j = 0; j < 5; j += 1) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

