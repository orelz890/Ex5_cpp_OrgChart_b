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

    class my_iterator{

        private:
        vector<worker*> root;
        int pos;

        public:
        my_iterator(vector<worker>& emps){
            this->pos = 0;
            for (int i = 0; i < emps.size(); i++)
            {
                this->root.emplace_back(&emps.at(i));
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

}