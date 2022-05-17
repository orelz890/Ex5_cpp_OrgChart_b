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

    template<typename T> class my_iterator{

        private:
        vector<worker*> root;

        public:
        my_iterator(){

        }

        my_iterator(const vector<worker>& chart){
            for (worker& w : chart)
            {
                root.emplace_back(&w);
            }
        }

        T& operator*() const{     
            return root.front()->name;
        }

        T* operator->() const{
            return &(this->front()->name);
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
            return root.size() > 0 && element.size() > 0 && root.front()->name == *element;
        }

        bool operator!=(const my_iterator& element) const{
            return !((*this) == element);
        }

        int size(){
            return root.size();
        }

    };

}