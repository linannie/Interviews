#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
  int odd, even, tens; 
 
  ifstream inf(argv[1]);

  while(inf >> odd >> even >> tens){
    cout << odd << " " << even << " " << tens << endl;
  } 
 
  return 0;
}
