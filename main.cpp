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

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "ahnen.h"
using namespace std;

int main(int argc, char** argv) 
{
    if (argc != 2) {

      cout << "Please enter the fullu qualified filename.\n";
      return 0;
    }    

    // todo: Confirm the file exists

    vector<Ahnen> vec = build_ahnen(argv[1]);

   
    return 0;
}

