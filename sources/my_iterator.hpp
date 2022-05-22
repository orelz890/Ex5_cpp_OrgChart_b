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
    typedef struct employee
    {
        string name;
        string supirior_name;
        employee* supirior;
        employee* next_in_line;
        vector<employee*> his_emps;


        employee(string name, string supirior){
            this->name = name;
            this->supirior_name = supirior;
            this->supirior = NULL;
            this->next_in_line = NULL;
        }

        employee(string name, employee* sup)
        {
            this->name = name;
            this->supirior = sup;
            this->next_in_line = NULL;
            if (sup != NULL)
            {
                this->supirior_name = sup->name;
            }
            
        }
        employee& operator=(employee* w){
            this->name = w->name;
            this->supirior = w->supirior;
            this->supirior_name = w->supirior_name;
            // this->his_workers = w->his_workers;
            for (employee* emp : w->his_emps)
            {
                // this->his_workers.push_back(emp);
                this->his_emps.insert(this->his_emps.end(),emp);
            }
            
            return *this;
        }
    }employee;

    template<typename T> class my_iterator{

        private:
        employee* root;

        public:
        my_iterator(){
            // root.clear();
        }

        my_iterator(employee* emps){
            this->root = emps;
        }

        T& operator*() const{
            return root->name;
        }

        T* operator->() const{
            return &(this->root->name);
        }

        my_iterator& operator++(){
            this->root = this->root->next_in_line;
            return *this;
        }

        const my_iterator operator++(int){
            my_iterator ans = *this;
            this->root = this->root->next_in_line;
            return ans;
        }

        bool operator==(const my_iterator& element) const{
            return this->root->name == *element;
        }

        bool operator!=(const my_iterator& element) const{
            return !(this->root->name == *element);
        }

    };

}