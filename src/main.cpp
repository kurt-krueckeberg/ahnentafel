/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kurt
 *
 * Created on May 25, 2021, 4:01 PM
 */
// toddo:: Change the headers to use clang's support for modules.
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "ahnen.h"

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

    for (auto i = 0; i < vec.size(); ++i) {

       auto father_anum = stoi(vec[i].number();

       if ((father_anum % 2) == 0) { // Is even -> father
          
           if (
       }
    }   
    return 0;
}

