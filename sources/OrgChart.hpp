#pragma once

#include "my_iterator.hpp"

using namespace std;

namespace ariel
{
    typedef struct Node
    {
        string name;
        Node* supirior;
        vector<Node> his_workers;
    }worker , *workers;


    class OrgChart
    {
        private:
        
        vector<worker> employees;

        public:
        
        // Constructors
        OrgChart();

        // Getter & setters
        int get_size(){
            return employees.size();
        }
        worker& get_emp_at(int pos){
            return employees.at((unsigned int)pos);
        }
        void add_employee(worker &emp){
            employees.emplace_back(emp);
        }
        void del_employee(worker &emp){
            for (int i = 0; i < employees.size(); i++)
            {
                if (strcmp(emp.name.c_str() , employees.at((unsigned int)i).name.c_str()) == 0)
                {
                    for (int j = 0; j < employees.at((unsigned int)j).his_workers.size(); j++)
                    {
                        employees.at((unsigned int)i).his_workers.at((unsigned int)j).supirior = employees.at((unsigned int)i).supirior; 
                    }
                    employees.erase(employees.begin() + i);
                    break;
                }
            }
        }

        // Funcs
        OrgChart& add_root(string supirior_name);
        OrgChart& add_sub(string a, string b);

        // Iterators
        string* begin();
        string* end();
        string* begin_level_order();
        string* end_level_order();
        string* begin_reverse_order();
        string* reverse_order();
        string* begin_preorder();
        string* end_preorder();

        // Operators
        friend ostream& operator<<(ostream& output, OrgChart& new_data);

    };

}