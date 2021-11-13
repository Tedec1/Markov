/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include <vector>
#include <iostream>
#include "map_model.h"

void map_model::initialize(string text, int order) {
    text += text.substr(0,order);
    for (int i = 0; i + order < text.length(); i++) {
        string sub = text.substr(i,order);
        if(_model.count(sub)){
            _model[sub].push_back(text[i + order]);
        } else {
            _keys.push_back(sub);
            _model[sub] = { text[i + order] };
        }
    }

}

string map_model::generate(int size) {
    string seed = _keys[rand() % _keys.size()];
    string gen{};
    for( int i = 0; i < size; i++ ){
        char next_char = _model[seed][rand() % _model[seed].size()];
        gen += next_char;
        seed = seed.substr(1) + next_char;
    }
    return gen;
}

