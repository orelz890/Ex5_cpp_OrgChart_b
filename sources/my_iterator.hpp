#pragma once
#include <string>
#include <string.h>
#include <iterator>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>


const int REVERSE_ORDER = 1;
const int LEVEL_ORDER = 2;
const int PRE_ORDER = 3;

namespace ariel
{
    typedef struct employee
    {
        public:
        std::string name;
        std::string supirior_name;
        employee* supirior;
        employee* next_in_line;
        std::vector<employee*> his_emps;


        employee(std::string name, std::string supirior){
            this->name = std::move(name);
            this->supirior_name = std::move(supirior);
            this->supirior = NULL;
            this->next_in_line = NULL;
        }

        employee(std::string name, employee* sup)
        {
            this->name = std::move(name);
            this->supirior = sup;
            this->next_in_line = NULL;
            if (sup != NULL)
            {
                this->supirior_name = sup->name;
            }
            
        }


        employee& operator=(employee* w){
            if (this != w)
            {
                this->name = w->name;
                this->supirior = w->supirior;
                this->supirior_name = w->supirior_name;
                this->next_in_line = w->next_in_line;
                for (employee* emp : w->his_emps)
                {
                    this->his_emps.push_back(emp);
                }
            }
                
            return *this;
        }
    }employee;


    template<typename T> class my_iterator{

        private:
        employee* root;

        public:
        my_iterator(){
            root = NULL;
        }

        my_iterator(employee* emps){
            root = emps;
        }

        T& operator*() const{            
            return this->root->name;
        }

        T* operator->() const{
            return &(this->root->name);
        }

        my_iterator& operator++(){
            this->root = this->root->next_in_line;
            return *this;
        }

        my_iterator operator++(int){
            my_iterator ans = *this;
            this->root = this->root->next_in_line;
            return ans;
        }

        bool operator==(const my_iterator& element) const{
            return this->root == element.root;
        }

        bool operator!=(const my_iterator& element) const{
            return !(*this == element);
        }

    };

}
