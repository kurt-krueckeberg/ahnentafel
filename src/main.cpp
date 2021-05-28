#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <utility>
#include "ahnen.h"
 
std::pair<int, int> get_name_widths(const std::vector<Ahnen>& vec)
{
   auto f_max = 0; 
   auto m_max = 0;
   for (auto&& x : vec) {

          if (0 == stoi(x.number()) % 2)
             f_max = (x.name().size() > f_max) ? x.name().size() : f_max;
          else 
             m_max = (x.name().size() > m_max) ? x.name().size() : m_max;
   }
   return {f_max, m_max};
}

using namespace std;
namespace fs = std::filesystem;
int main(int argc, char** argv) 
{
    if (argc != 2) {

      cout << "Please enter the fully qualified filename.\n";
      return 0;
      
    }  else if (!fs::exists(argv[1])) {
        
        cout << "File '" << argv[1] << "' does not exist. Enter a valid fully qualified filename.\n";
    }  

    vector<Ahnen> vec = build_ahnen(argv[1]);

    auto prev_father = 1;

    ofstream ofstr("./data/output.txt");

    auto anum_width = vec[vec.size() - 1].number().size();

    auto [father_width, mother_width] = get_name_widths(vec);
    
    for (auto i = 0; i < vec.size();) {
       
       auto father_anum = stoi(vec[i].number());

       auto remainder = father_anum % 2;

      // Does a mother exist for this father?
       // The next entry is even, a man, so we create an "Unknown" wife.
       ofstr << std::right << setw(anum_width) << setfill('0') << father_anum << '_' << setw(anum_width) << setfill('0') << father_anum + 1 << " [" << vec[i].name() << " ]  [";
 
       auto mother_index = i + 1;
       
       if (stoi(vec[mother_index].number()) != father_anum + 1) {
           
             ofstr <<  "Unknown";
             
             ++i;
             
       } else {
           
          ofstr << vec[mother_index].name();
          
          i+=2;
       }
       ofstr << " ]\n";
       
    }  
    /*
    for (auto i = 0; i < vec.size();) {
       
       auto father_anum = stoi(vec[i].number());

       auto remainder = father_anum % 2;

      // Does a mother exist for this father?
       // The next entry is even, a man, so we create an "Unknown" wife.
       ofstr << std::right << setw(anum_width) << setfill('0') << father_anum << '_' << setw(anum_width) << setfill('0') << father_anum + 1 << " [" << setw(father_width) << std::left << setfill(' ') << vec[i].name() << " ]  [";
 
       auto mother_index = i + 1;
       
       if (stoi(vec[mother_index].number()) != father_anum + 1) {
           
             ofstr << setw(mother_width) << setfill(' ') << std::left << "Unknown";
             
             ++i;
             
       } else {
           
          ofstr  << setw(mother_width) << setfill(' ') << std::left << vec[mother_index].name();
          
          i+=2;
       }
       ofstr << " ]\n";
       
    }  
     */  
    return 0;
}

