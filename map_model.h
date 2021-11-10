/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <string>
#include <unordered_map>
#include "model.h"

using namespace std;

class map_model : public markov_model {
public:
    void initialize(string text, int order) override;

    string generate(int size) override;

    string to_string();

protected:
    unordered_map<char,vector<char>> _model = {};
    // Add any variables you may need here
};

#endif
