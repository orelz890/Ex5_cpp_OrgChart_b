#pragma once
#include <string>
#include <string.h>
#include <iterator>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

namespace ariel
{
    class my_iterator{
        private:
        vector<string> root;

        public:
        my_iterator(vector<string>& emps){
            this->root = emps;
        }
        my_iterator& operator++();
        my_iterator operator++(int);
        bool operator==(const my_iterator& element) const;
        bool operator!=(const my_iterator& element) const;
    };

}