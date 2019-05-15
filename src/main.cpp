#include <iostream>
#include <string>
#include <vector>
#include "zadatak.h"

using namespace std;


int main(void){

  vector<string> za_datoteku;
  string datoteka = "text.txt";

  readFile(datoteka, za_datoteku);

  for (unsigned i = 0; i < za_datoteku.size(); ++i){
    cout << za_datoteku[i] << " ";
  }
  cout << endl;

  X klasa(za_datoteku);
  klasa.print(cout, 7);

  cout << endl;

  cout << klasa.max_br_suglasnika() << endl;
  
  return 0;
}
