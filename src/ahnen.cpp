#include "ahnen.h"
#include "token_iterator.h"
#include <fstream>
using namespace  std;

std::vector<Ahnen> build_ahnen(const std::string& fname)
{
   ifstream ifstr(fname);
   
   string input;
   vector<Ahnen> vec;
   
   while (getline(ifstr, input)) {
       
       token_iterator<'.'> token_iter(input);
       
       vec.push_back({*token_iter, *++token_iter});
   }
   return vec;
} 
