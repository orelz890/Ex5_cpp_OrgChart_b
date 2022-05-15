
#include "OrgChart.hpp"

namespace ariel
{
    OrgChart::OrgChart(){
        
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
        string ans[employees.size()];
        
        return ans;
    }

    string* OrgChart::begin_reverse_order(){
        string ans[employees.size()];
        
        return ans;

    }
    string* OrgChart::reverse_order(){
        string ans[employees.size()];
        
        return ans;
    }
    string* OrgChart::begin_preorder(){
        string ans[employees.size()];
        
        return ans;
    }
    string* OrgChart::end_preorder(){
        string ans[employees.size()];
        
        return ans;
    }

    // Operators
    ostream& operator<<(ostream& output, OrgChart& new_data){
        return output;
    }

}