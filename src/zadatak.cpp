#include "zadatak.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

void readFile(std::string const & fileName,
              std::vector<std::string> & words)
{
  string line = "";
  ifstream in;

  in.open(fileName);
  if(!in)
    throw runtime_error("Ne mogu otvoriti datoteku " +
                        fileName + "za čitanje!");

  while (getline(in, line)) {
    istringstream iss(line);
    string word = "";
    while (iss >> word)
      words.push_back(word);
  }

  for (unsigned int i = 0; i < words.size(); i++) {
    //postavi na prvi karakter i brisi dok je interpunkcija
    char c = words[i][0];
    while (c == ',' || c == '.' || c == ';' || c == ':' ||
          c == '(' || c == ')' || c == '"'){
          words[i].erase(0,1);
          c = words[i][0];
    }
    //postavi na zadnji karakter i brisi dok je interpunkcija
    c = words[i][words[i].size()-1];
    while (c == ',' || c == '.' || c == ';' || c == ':' ||
          c == '(' || c == ')' || c == '"'){
          words[i].erase(words[i].size()-1,1);
          c = words[i][words[i].size()-1];
    }
  }
  //ne radi jer brise i karaktere u stringu a ne oko njega
    //za svaki string trazi karakter i brisi ga dok ga pronalazis
    /*unsigned int koji = words[i].find_first_of(",.;:)(\"");
    while (koji != string::npos) {
      words[i].erase(koji, 1);
      koji = words[i].find_first_of(",.;:)(\"");
    }*/

  in.close();
}

// konstruktor
X::X(std::vector<std::string> const & words)
{
  for (auto iter = words.begin(); iter != words.end(); ++iter) {
    //broji svaki char iz stringa koji je suglasnik
    auto iter_str_pocetni = iter->begin();
    auto iter_str_krajnji = iter->end();
    int broj = count_if (iter_str_pocetni, iter_str_krajnji,
                        [](char c){
                          if (c == 'a' || c == 'e' || c == 'i' ||
                            c == 'o' || c == 'u' || c == 'A' || c == 'E' ||
                            c == 'I' || c == 'O' || c == 'U')
                            return false;
                          else return true;
                        });
    M[*iter] = broj;
    if (broj > maks)
      maks = broj;
  }
}


int X::max_br_suglasnika() const
{
  return maks;
}


void X::print(std::ostream &out, int k) const
{
  for (auto it = M.begin(); it != M.end(); ++it)
    if (it->second == k)
      out << it->first << " ";
}
