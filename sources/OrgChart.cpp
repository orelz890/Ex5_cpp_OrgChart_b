
#include "OrgChart.hpp"

namespace ariel
{
    OrgChart::OrgChart(){
        this->root = NULL;
    }
    // Funcs
    OrgChart& OrgChart::add_root(string supirior_name){

        worker new_emp;
        new_emp.name = supirior_name;
        new_emp.supirior = NULL;
        
        if (this->employees.empty())
        {
            add_employee(new_emp);
        }
        else
        {
            new_emp.his_workers = this->employees.at(0).his_workers;
            this->employees.at(0) = new_emp;    
        }
        this->root = &this->employees.at(0);
        return *this;
    }

    // template<typename T> OrgChart& OrgChart::add_sub(T a, T b){
        
    // }

    OrgChart& OrgChart::add_sub(string supirior, string new_emp){
        worker temp;
        temp.name = new_emp;
        add_employee(temp);
        for(worker emp : this->employees){
            if (emp.name == supirior)
            {
                temp.supirior = &emp;
                emp.his_workers.emplace_back(temp);
            }
        }
        return *this;
    }
    
    // Iterators
    string* OrgChart::begin(){
        return begin_level_order();
    }

    string* OrgChart::end(){
        return end_level_order();
    }

    string* OrgChart::begin_level_order(){
        string ans[employees.size()];
        int i = 0;
        if (!employees.empty())
        {
            queue <worker*> Q;
            Q.push(&this->employees.at(0));
            while(!Q.empty())
            {
                worker* supirior = Q.front();
                ans[i++] = (*supirior).name;
                for (worker& subordinate : supirior->his_workers)
                {
                    Q.push(&subordinate);
                }
                Q.pop();
            }
        }
        return ans;
    }

    string* OrgChart::end_level_order(){
        string* level_order_it = begin_level_order();
        return &(level_order_it[employees.size() - 1]);
    }

    string* OrgChart::begin_reverse_order(){
        string ans[employees.size()];
        int i = 0;
        stack<worker*> S;
        queue<worker*> Q;
        worker* supirior;
        while (!Q.empty())
        {
            supirior = Q.front();
            Q.pop();
            S.push(supirior);
            // Push his subordinates from right to left to our queue
            for (int j = supirior->his_workers.size() - 1; j >= 0; j--)
            {
                Q.push(&supirior->his_workers.at((unsigned int)j));
            }
        }
        while (!S.empty())
        {
            supirior = S.top();
            ans[i++] =  supirior->name;
            S.pop();
        }
        
        return ans;

    }

    string* OrgChart::reverse_order(){
        string* reverse_order_it = begin_reverse_order();
        return &(reverse_order_it[employees.size() - 1]);
    }

    string* OrgChart::begin_preorder(){
        string ans[employees.size()];
        int i = 0;
        stack<worker*> S;
        S.push(root);
        while (!S.empty())
        {
            worker* supirior = S.top();
            ans[i++] = supirior->name;
            S.pop();
            for (int j = supirior->his_workers.size() - 1; j >= 0; j--)
            {
                S.push(&(supirior->his_workers.at((unsigned int)j)));
            }
        }
        return ans;
    }

    string* OrgChart::end_preorder(){
        string* pre_order_it = begin_preorder();
        return &pre_order_it[employees.size() - 1];
    }

    // Operators
    ostream& operator<<(ostream& output, OrgChart& new_data){
        string* level_order_it = new_data.begin_level_order();
        for (int i = 0; i < new_data.employees.size(); i++)
        {
            output << level_order_it[i] << " ";
        }
        output << '\n';
        return output;
    }

}