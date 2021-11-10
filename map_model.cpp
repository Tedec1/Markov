/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include <vector>
#include <iostream>
#include "map_model.h"

void map_model::initialize(string text, int order) {
    vector<string> keys;
    text += text.substr(0,order);
    for (int i = 0; i + order < text.length(); i++) {
        string sub = text.substr(i,order);
        if(_model.count(sub)){
            _model[sub].push_back(text[i + order]);
        } else {
            keys.push_back(sub);
            _model[sub] = { text[i + order] };
        }
    }
    for (const string& key:keys) {
        cout << key + ": ";
        for (char c: _model[key]) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}

string map_model::generate(int size) {


    return "the fox jumped over the moon";
}
