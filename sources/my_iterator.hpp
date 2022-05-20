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
        vector<employee*> his_emps;

        employee(string name, string supirior){
            this->name = name;
            this->supirior_name = supirior;
        }

        employee(string name, employee* sup)
        {
            this->name = name;
            this->supirior = sup;
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
        vector<employee*> root;

        public:
        my_iterator(){
            // root.clear();
        }

        my_iterator(employee* node){
            queue<employee*> Q;
            Q.push(node);

            while (!Q.empty())
            {
                employee* w = Q.front();
                this->root.push_back(w);
                for (int i = 0; i < w->his_emps.size(); i++)
                {
                    Q.push(w->his_emps.at((unsigned long)i));
                }
                Q.pop();
            }
            std::cout << root.size() << " nodes added to the iterator\n";
        }

        T& operator*() const{
            return root.front()->name;
        }

        T* operator->() const{
            return &(this->root.front()->name);
        }

        my_iterator& operator++(){
            root.erase(root.begin());
            return *this;
        }

        const my_iterator operator++(int){
            my_iterator ans = *this;
            root.erase(root.begin());
            return ans;
        }

        bool operator==(const my_iterator& element) const{
            return root.size() > 0 && element.it_size() > 0 && root.front()->name == *element;
        }

        bool operator!=(const my_iterator& element) const{
            return !(root.size() > 0 && element.it_size() > 0 && root.front()->name == *element);
        }

        int it_size() const{
            return root.size();
        }

    };

}