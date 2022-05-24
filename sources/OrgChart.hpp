#pragma once

#include "my_iterator.hpp"
#include <stack>
#include <queue>
#include <map>


namespace ariel
{
    class OrgChart
    {
        public:
        using Iterator = my_iterator<std::string>;

        private:     
        employee* root;
        employee* reverse_root;
        int size;

        public:

        // Constructors
        OrgChart();
        OrgChart(const OrgChart& other);
        OrgChart(OrgChart&& other) noexcept;
        ~OrgChart();

        // Helpers:
        void level_order_tree();
        void pre_order_tree();
        void reverse_order_tree();

        // Funcs
        OrgChart& add_root(std::string supirior_name);
        OrgChart& add_sub(std::string supirior_name, std::string new_emp_name);

        // Iterators
        Iterator begin();
        Iterator end();
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        // Operators
        OrgChart& operator=(const OrgChart& other);
        OrgChart& operator=(OrgChart&& other) noexcept;

        friend std::ostream& operator<<(std::ostream& output, OrgChart& new_data);

    };

}