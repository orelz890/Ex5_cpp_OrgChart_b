#pragma once

#include "my_iterator.hpp"
#include <stack>
#include <queue>
#include <map>

const int REVERSE_ORDER = 1;
const int LEVEL_ORDER = 2;
const int PRE_ORDER = 3;

using namespace std;

namespace ariel
{
    
    class OrgChart
    {
        
        private:     
        vector<worker> employees;
        p_worker root;
        int longest_str;

        public:
        
        // Constructors
        OrgChart();

        // Getter & setters
        int get_size(){
            return employees.size();
        }

        vector<worker> get_employees(){
            return this->employees;
        }

        p_worker get_emp_at(int pos){
            return &employees.at((unsigned long)pos);
        }

        // Helpers:
        void level_order_tree();
        void pre_order_tree();
        void reverse_order_tree();

        // Funcs
        OrgChart& add_root(string supirior_name);
        OrgChart& add_sub(string a, string b);

        // Iterators
        my_iterator<string> begin();
        my_iterator<string> end();
        my_iterator<string> begin_level_order();
        my_iterator<string> end_level_order();
        my_iterator<string> begin_reverse_order();
        my_iterator<string> reverse_order();
        my_iterator<string> begin_preorder();
        my_iterator<string> end_preorder();

        // Operators
        friend ostream& operator<<(ostream& output, OrgChart& new_data);

    };

}