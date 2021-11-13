/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#include <iostream>
#include <sstream>
#include "word_model.h"

string word_model::_remove_first_word(string &s) {
    int i = 0;
    while(i < s.length()){
        if(s[i] == ' '){
            break;
        }
        i++;
    }
    string a = s.substr(0,i);
    s = s.substr(i);
    if(s[0] == ' ' && s.length() != 1){
        s = s.substr(1);
    }
    return a;
}

string word_model::_find_kth_words(string &s, int order, int starting_i){
    int count = 0;
    int i = starting_i;
    if(starting_i > s.length()){
        throw exception();
    }
    while(count != order && i < s.length()){
        if ( s[i] == ' ' ) {
            count++;
        }
        if(count == order){
            break;
        }
        i++;
    }
    return s.substr(0,i);
}

void word_model::initialize(string text, int order) {
    stringstream ss;
    bool first_kth_words = true;
    string cur_key{};
    string s;
    while(!text.empty()){
        string words_to_add{};
        words_to_add += _remove_first_word(text) + ' ';
        words_to_add += _find_kth_words(text,order - 1,0);
        if(first_kth_words){
            cur_key = words_to_add;
            text += " " + words_to_add;
            first_kth_words = false;
            continue;
        }
        if(_model.count(cur_key)){
            _model[cur_key].push_back(s);
        } else {
            _keys.push_back(cur_key);
            _model[cur_key] = {s};
        }
        cur_key = s;
    }
    for (string key:_keys) {
         cout << key<< ": ";
        for (string s: _model[key]) {
            cout << s + ", ";
        }
        cout << '\n';
    }
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
