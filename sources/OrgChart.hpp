#pragma once

#include "my_iterator.hpp"
#include <stack>
#include <queue>
#include <map>

const int REVERSE_ORDER = 1;
const int LEVEL_ORDER = 2;
const int PRE_ORDER = 3;

namespace ariel
{
    
    class OrgChart
    {
        
        private:     
        employee* root;
        employee* reverse_root;
        int size;
        int longest_str;

        public:

        // Constructors
        OrgChart();
        OrgChart(const OrgChart& other);
        ~OrgChart();
        // Getter & setters
        int get_size(){
            return size;
        }
        employee* get_root();

        // Helpers:
        void level_order_tree();
        void pre_order_tree();
        void reverse_order_tree();

        // Funcs
        OrgChart& add_root(std::string supirior_name);
        OrgChart& add_sub(std::string supirior_name, std::string new_emp_name);

        // Iterators
        my_iterator<std::string> begin();
        my_iterator<std::string> end();
        my_iterator<std::string> begin_level_order();
        my_iterator<std::string> end_level_order();
        my_iterator<std::string> begin_reverse_order();
        my_iterator<std::string> reverse_order();
        my_iterator<std::string> begin_preorder();
        my_iterator<std::string> end_preorder();

        // Operators
        OrgChart& operator=(const OrgChart& other);

        friend std::ostream& operator<<(std::ostream& output, OrgChart& new_data);

    };

}