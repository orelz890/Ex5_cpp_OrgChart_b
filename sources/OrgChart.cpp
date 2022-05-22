// In this part i was aided by this site:
// https://www.geeksforgeeks.org/reverse-level-order-traversal


#include "OrgChart.hpp"
#include <unistd.h>

namespace ariel
{
    OrgChart::OrgChart()
    {
        this->size = 0;
        int longest_str = 0;
        this->root = NULL;
        this->end_of_order = NULL;
    }

    // Funcs
    OrgChart& OrgChart::add_root(string supirior_name)
    {
        if (this->root != NULL)
        {
            this->root->name = supirior_name;
        }
        else
        {
            employee* a = new employee{supirior_name,NULL};
            this->root = a;
            this->size++;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(string supirior_name, string new_emp_name)
    {
        if (this->root->name != supirior_name)
        {
            bool flag = true;
            queue<employee*> Q;
            Q.push(this->root);
            employee* sup;
            employee* sub;
            while (!Q.empty() && flag)
            {
                sup = Q.front();
                if (!sup->his_emps.empty())
                {
                    for (unsigned long i = 0; i < sup->his_emps.size(); i++){
                        sub = sup->his_emps.at(i);
                        cout << sup->name << " is " << sub->name << "'s supirior\n";
                        // sleep(1);
                        Q.push(sub);
                        if (sub->name == supirior_name)
                        {
                            employee* new_emp = new employee(new_emp_name,sub);
                            sub->his_emps.push_back(new_emp);
                            this->size++;
                            flag = false;
                            break;
                        }
                    }
                }
                Q.pop();
            }
        }
        else
        {
            employee* new_emp = new employee(new_emp_name,this->root);
            this->root->his_emps.push_back(new_emp);
            this->size++;
        }
        return *this;
    }

    void OrgChart::level_order_tree(){
        // string ans[this->size];
        employee* last_emp = NULL;
        int i = 0;
        if (this->size > 0)
        {
            queue<employee*> Q;
            Q.push(this->root);
            employee* supirior;
            while (!Q.empty())
            {
                supirior = Q.front();
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL;
                // ans[i++] = supirior->name;
                // cout << "curr child = " << supirior->name << " and he has " 
                //      << supirior->his_emps.size() << " kids\n"; 
                     
                for (unsigned long j = 0; j < supirior->his_emps.size(); j++)
                {
                    Q.push(supirior->his_emps.at(j));
                }
                this->end_of_order = supirior;
                Q.pop();
            }
        }
        // for (string& s : ans)
        // {
        //     cout << s << "\n";
        // }
    }

    void OrgChart::pre_order_tree(){
        // string ans[this->size];
        employee* last_emp = NULL;
        int i = 0;
        stack<employee*> S;
        if (this->size > 0)
        {
            
            S.push(this->root);
            employee* supirior;
            while (!S.empty())
            {
                supirior = S.top();
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL;
                // ans[i++] = supirior->name;
                this->end_of_order = supirior;
                S.pop();
                for (int j = supirior->his_emps.size() - 1; j >= 0; j--)
                {
                    S.push(supirior->his_emps.at((unsigned int)j));
                }
            }

            // for (string& s : ans)
            // {
            //     cout << s << "\n";
            // }
        }
    }

    void OrgChart::reverse_order_tree(){
        // string ans[this->size];
        employee* last_emp = NULL;
        if (this->size > 0)
        {
        
            int i = 0;
            employee* supirior;
            stack<employee*> S;
            queue<employee*> Q;
            Q.push(this->root);

            while (!Q.empty())
            {
                supirior = Q.front();
                Q.pop();
                S.push(supirior);
                // Push his subordinates from right to left to our queue
                for (int j = supirior->his_emps.size() - 1; j >= 0; j--)
                {
                    Q.push(supirior->his_emps.at((unsigned int)j));
                }
            }
            while (!S.empty())
            {
                supirior = S.top();
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL;
                // ans[i++] = supirior->name;
                this->end_of_order = supirior;
                S.pop();
            }

            // for (string& s : ans)
            // {
            //     cout << s << "\n";
            // }
        }
    }

    // Iterators
    my_iterator<string> OrgChart::begin()
    {
        return begin_level_order();
    }

    my_iterator<string> OrgChart::end()
    {
        return end_level_order();
    }

    my_iterator<string> OrgChart::begin_level_order()
    {
        this->level_order_tree();
        return my_iterator<string>{this->root};
    }

    my_iterator<string> OrgChart::end_level_order()
    {
        return my_iterator<string>{this->end_of_order};
    }

    my_iterator<string> OrgChart::begin_reverse_order()
    {
        this->reverse_order_tree();
        return my_iterator<string>{this->root};
    }

    my_iterator<string> OrgChart::reverse_order()
    {
        return my_iterator<string>{this->end_of_order};
    }

    my_iterator<string> OrgChart::begin_preorder()
    {
        this->pre_order_tree();
        return my_iterator<string>{this->root};
    }

    my_iterator<string> OrgChart::end_preorder()
    {
        return my_iterator<string>{this->end_of_order};
    }

    // Operators
    ostream &operator<<(ostream &output, OrgChart &new_data)
    {
        // string *level_order_it = new_data.begin_level_order();
        int size = new_data.size;
        map<pair<string, string>, int> mat;
        unsigned long longest_str = 0;
        vector<string> all_emps;

        // Find the longest name & fill the mat --> if a is b's subordinate than mat(a,b) = 1 else mat(a,b) = 0.
        queue<employee*> Q;
        Q.push(new_data.root);
        employee* emp;
        while (!Q.empty())
        {
            emp = Q.front();
            all_emps.push_back(emp->name);
            for(employee* sub : emp->his_emps){
                Q.push(sub);
            }
            if (emp->name.size() > longest_str)
            {
                longest_str = emp->name.size();
            }
            Q.pop();
        }

        for (string sup : all_emps)
        {
            for (string sub : all_emps)
            {
                pair<string,string> key = {sup,sub};
                mat[key] = 0;
            }
        }
        
        // Pritty drawing
        output << '\n'
               << string((longest_str - new_data.root->name.size())/2, ' ') << "p\\c" 
               << string(longest_str - (longest_str - new_data.root->name.size())/2 -3, ' ') << '|';
        
        Q.push(new_data.root);
        while (!Q.empty())
        {
            emp = Q.front();
            for(employee* sub : emp->his_emps){
                Q.push(sub);
                pair<string, string> key = {emp->name, sub->name};
                mat[key] = 1;
            }
            // varifiying that child is not root
            if(emp->supirior != NULL){
                output <<string((longest_str - emp->name.size())/2, ' ') << emp->name 
                    << string((longest_str - emp->name.size())/2 + 1, ' ') << '|';
            }
            Q.pop();
        }
        output << '\n' << string((longest_str + 2) * (unsigned long)(new_data.size), '-') << '\n';
        
        for (string& sup : all_emps)
        {
            output << string((longest_str - sup.size())/2, ' ') << sup 
                << string((longest_str - sup.size())/2 , ' ') << '|';
            
            for (string& sub : all_emps)
            {
                if (sub != new_data.root->name)
                {
                    pair<string, string> pos = {sup,sub};
                    output << string(longest_str / 2, ' ') << mat.at(pos)
                        << string(longest_str - (longest_str / 2), ' ') << '|';
                }
                
            }
            // output << "\n";
            output << "\n" << string((longest_str + 2) * (unsigned long)(new_data.size), '-') << '\n';            
        }
        
        return output << '\n';
    }

}