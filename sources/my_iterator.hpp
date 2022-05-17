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
            *this = w;
            // this->name = w.name;
            // this->supirior = w.supirior;
            // this->his_workers = w.his_workers;
            // // for (int i = 0; i < w.his_workers.size(); i++)
            // // {
            // //     this->his_workers.emplace_back(w.his_workers.at(i));
            // // }
            return *this;
        }
    }worker , *p_worker;

    template<typename T> class my_iterator{

        private:
        vector<worker*> root;

        public:
        my_iterator(){
            // root.clear();
        }

        my_iterator(p_worker node){
            queue<p_worker> Q;
            Q.push(node);

            while (!Q.empty())
            {
                p_worker w = Q.front();
                this->root.push_back(w);
                for (int i = 0; i < w->his_workers.size(); i++)
                {
                    Q.push(w->his_workers.at((unsigned long)i));
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