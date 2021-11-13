/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include <unordered_map>
#include "model.h"
#include <vector>
using namespace std;

class word_model : public markov_model {
public:
    void initialize(string text, int order) override;

    string generate(int size) override;

    // Add any helper methods you want here

protected:
    unordered_map<string,vector<string>> _model = {};
    vector<string> _keys;
    static string _remove_first_word(string &s);

    string _find_kth_words(string &s, int order,int startingi);
};

#endif
