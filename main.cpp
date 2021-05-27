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
#include "token_iterator.h"
 
using namespace std;

class Ahnen {
    string num_;
    string name_;
public:
    Ahnen(const std::string_view& num, const std::string_view& name) : num_{num}, name_{name} {}
    Ahnen(Ahnen&& lhs) = default;
    Ahnen(const Ahnen&) = default;
    //...
};


int main(int argc, char** argv) 
{
    
    ifstream ifstr("/home/kurt/temp/ahnentafel.txt");
    
    string input;
    vector<Ahnen> vec;
    
    while (getline(ifstr, input)) {
        
        token_iterator<'.'> token_iter(input);
        
        vec.push_back({*token_iter, *++token_iter});
        
    }
    
    return 0;
}

