#pragma once

#include "my_iterator.hpp"
#include <stack>
#include <map>

using namespace std;

namespace ariel
{
    typedef struct worker
    {
        string name;
        string supirior;
        vector<worker*> his_workers;
        // Node operator=(Node& a){
        //     this->name = a.name;
        //     this->his_workers = a.his_workers;
        //     this->supirior = a.supirior;
        // }
    }worker , *p_worker;


    class OrgChart
    {
        private:
        
        vector<worker> employees;
        p_worker root;
        int longest_str;
        string* level_order_it;
        string* pre_order_it;
        string* reverse_order_it;

        public:
        
        // Constructors
        OrgChart();

        // Getter & setters
        int get_size(){
            return employees.size();
        }
        // vector<p_worker> get_print_prity(){
        //     return this->print_prity;
        // }
        vector<worker> get_employees(){
            return this->employees;
        }       

        worker& get_emp_at(int pos){
            return employees.at((unsigned int)pos);
        }
        // void del_employee(worker &emp){
        //     for (int i = 0; i < employees.size(); i++)
        //     {
        //         if (strcmp(emp.name.c_str() , employees.at((unsigned int)i).name.c_str()) == 0)
        //         {
        //             for (int j = 0; j < employees.at((unsigned int)j).his_workers.size(); j++)
        //             {
        //                 employees.at((unsigned int)i).his_workers.at((unsigned int)j)->supirior = employees.at((unsigned int)i).supirior; 
        //             }
        //             employees.erase(employees.begin() + i);
        //             break;
        //         }
        //     }
        // }

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