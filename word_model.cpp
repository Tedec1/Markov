/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#include <iostream>
#include <sstream>
#include "word_model.h"


string word_model::_make_key(const vector<string>& list, int order, int start){
    string res{};
    int count = 0;
    int i = start;
    while (count < order){
        if(i > list.size()){
            i = 0;
        }
        res += " " + list[i];
        i++;
        count++;
    }
    return res.substr(1);
}

void word_model::initialize(string text, int order) {
    stringstream ss(text);
    string s;
    vector<string> list;
    while(ss >> s){
        list.push_back(s);
    }
    for (int i = 0; i < order; ++i) {
        list.push_back(list[i]);
    }
    for (int i = 0; i + order < list.size(); ++i) {
        string key = _make_key(list,order,i);
        if(_model.count(key)){
            _model.at(key).push_back(list[i + order]);
        } else {
            _model[key] = {list[i + order]};
            _keys.push_back(key);
        }
    }
}

void word_model::_remove_first_word(string &seed){
    int i = 0;
    while (seed[i] != ' ' && i != seed.length()){
        i++;
    }
    if(i == seed.length()){
        seed.clear();
        return;
    }
    seed = seed.substr(i + 1) + " ";
}

string word_model::generate(int size) {
    string seed = _keys[rand() % _keys.size()];
    string gen{};
    for (int i = 0; i < size; ++i) {
        string next_word = _model[seed][rand() % _model[seed].size()];
        gen += next_word + " ";
        _remove_first_word(seed);
        seed += next_word;
    }
    return gen;
}
