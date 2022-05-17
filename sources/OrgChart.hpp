#pragma once

// #include "my_iterator.hpp"
#include <stack>
#include <queue>
#include <map>

const int REVERSE_ORDER = 1;
const int LEVEL_ORDER = 2;
const int PRE_ORDER = 3;

using namespace std;

namespace ariel
{
    typedef struct worker
    {
        string name;
        string supirior;
        vector<worker*> his_workers;
        worker(){}
        worker(worker* w){
            this->name = w->name;
            this->supirior = w->supirior;
            this->his_workers = w->his_workers;
        }
        worker(string name, string supirior){
            this->name = name;
            this->supirior = supirior;
            // this->his_workers.clear();
        }

        worker& operator=(worker& w){
            this->name = w.name;
            this->supirior = w.supirior;
            this->his_workers = w.his_workers;
            // for (int i = 0; i < w.his_workers.size(); i++)
            // {
            //     this->his_workers.emplace_back(w.his_workers.at(i));
            // }
            
            return *this;
        }
    }worker , *p_worker;

    class OrgChart
    {
        template<typename T> class my_iterator{

            private:
            OrgChart* my_chart;
            int order_flag;
            int pos;


            public:
            my_iterator(OrgChart& chart, const int flag){
                this->my_chart = &chart;
                this->order_flag = flag;
                this->pos = 0;

                if (flag == 1)
                {
                    
                }
                else if(flag == 2)
                {

                }
                else if(flag == 3){

                }
            }

            T& operator*() const{
                return this->root.at(pos)->name;
            }

            T* operator->() const{
                return &(this->root.at(pos)->name);
            }

            my_iterator& operator++(){
                pos++;
                return *this;
            }

            const my_iterator operator++(int){
                my_iterator ans = *this;
                pos++;
                return ans;
            }

            bool operator==(const my_iterator& element) const{
                return this->root.at(pos)->name == element.root.at(element.pos)->name;
            }

            bool operator!=(const my_iterator& element) const{
                return !((*this) == element);
            }


        };

        private:     
        vector<worker> employees;

        int longest_str;
        string* level_order_it;
        string* pre_order_it;
        string* reverse_order_it;

        public:
        
        // Constructors
        OrgChart();
        ~OrgChart();

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