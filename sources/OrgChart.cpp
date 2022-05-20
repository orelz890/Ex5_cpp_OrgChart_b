// In this part i was aided by this site:
// https://www.geeksforgeeks.org/reverse-level-order-traversal

// How to run:
//g++ OrgChart.cpp my_iterator.cpp my_main.cpp my_iterator.hpp OrgChart.hpp

#include "OrgChart.hpp"
#include <unistd.h>

namespace ariel
{
    OrgChart::OrgChart()
    {
        this->size = 0;
        int longest_str = 0;
        this->root = NULL;
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
            worker* a = new worker{supirior_name,NULL};
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
            queue<worker*> Q;
            Q.push(this->root);
            worker* sup;
            worker* sub;
            while (!Q.empty() && flag)
            {
                sup = Q.front();
                if (!sup->his_workers.empty())
                {
                    for (unsigned long i = 0; i < sup->his_workers.size(); i++){
                        sub = sup->his_workers.at(i);
                        cout << sup->name << " is " << sub->name << "'s supirior\n";
                        // sleep(1);
                        Q.push(sub);
                        if (sub->name == supirior_name)
                        {
                            worker* new_emp = new worker(new_emp_name,sub);
                            sub->his_workers.push_back(new_emp);
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
            worker* new_emp = new worker(new_emp_name,this->root);
            this->root->his_workers.push_back(new_emp);
            this->size++;
        }
        return *this;
    }

    void OrgChart::level_order_tree(){
        string ans[this->size];
        vector<p_worker> new_order;
        int i = 0;
        if (this->size > 0)
        {
            queue<p_worker> Q;
            Q.push(this->root);

            while (!Q.empty())
            {
                p_worker supirior = Q.front();
                new_order.emplace_back(supirior);
                ans[i++] = supirior->name;
                cout << "curr child = " << supirior->name << " and he has " 
                     << supirior->his_workers.size() << " kids\n"; 
                     
                for (unsigned long j = 0; j < supirior->his_workers.size(); j++)
                {
                    Q.push(supirior->his_workers.at(j));
                }
                Q.pop();
            }
        }
        for (string& s : ans)
        {
            cout << s << "\n";
        }
    }

    void OrgChart::pre_order_tree(){
        string ans[this->size];
        vector<worker*> new_order;

        int i = 0;
        stack<worker*> S;
        if (this->size > 0)
        {
            
            S.push(this->root);
            while (!S.empty())
            {
                p_worker supirior = S.top();
                new_order.emplace_back(supirior);
                ans[i++] = supirior->name;
                S.pop();
                for (int j = supirior->his_workers.size() - 1; j >= 0; j--)
                {
                    S.push(supirior->his_workers.at((unsigned int)j));
                }
            }

            for (string& s : ans)
            {
                cout << s << "\n";
            }
        }
    }

    void OrgChart::reverse_order_tree(){
        string ans[this->size];
        vector<worker*> new_order;

        if (this->size > 0)
        {
        
            int i = 0;
            p_worker supirior;
            stack<p_worker> S;
            queue<p_worker> Q;
            Q.push(this->root);

            while (!Q.empty())
            {
                supirior = Q.front();
                Q.pop();
                S.push(supirior);
                // Push his subordinates from right to left to our queue
                for (int j = supirior->his_workers.size() - 1; j >= 0; j--)
                {
                    Q.push(supirior->his_workers.at((unsigned int)j));
                }
            }
            while (!S.empty())
            {
                supirior = S.top();
                new_order.emplace_back(supirior);
                ans[i++] = supirior->name;
                S.pop();
            }

            for (string& s : ans)
            {
                cout << s << "\n";
            }
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
        return my_iterator<string>{};
    }

    my_iterator<string> OrgChart::begin_reverse_order()
    {
        this->reverse_order_tree();
        return my_iterator<string>{this->root};
    }

    my_iterator<string> OrgChart::reverse_order()
    {
        return my_iterator<string>{};
    }

    my_iterator<string> OrgChart::begin_preorder()
    {
        this->pre_order_tree();
        return my_iterator<string>{this->root};
    }

    my_iterator<string> OrgChart::end_preorder()
    {
        return my_iterator<string>{};
    }

    // Operators
    ostream &operator<<(ostream &output, OrgChart &new_data)
    {
        // string *level_order_it = new_data.begin_level_order();
        int size = new_data.size;
        map<pair<string, string>, int> mat;
        unsigned long longest_str = 0;

        // Find the longest name & fill the mat --> if a is b's subordinate than mat(a,b) = 1 else mat(a,b) = 0.
        queue<worker*> Q;
        Q.push(new_data.root);
        worker* emp;
        while (!Q.empty())
        {
            emp = Q.front();
            for(worker* sub : emp->his_workers){
                Q.push(sub);
                if (!sub->supirior_name.empty())
                {
                    pair<string, string> key = {emp->name, sub->name};
                    mat[key] = 0;
                    if (sub->supirior_name == emp->name)
                    {
                        // cout << "perent = " << perent.name << " child = " << child.name << " child parent = "<< child.supirior << "\n";
                        mat[key] = 1;
                    }
                }
                if (emp->name.size() > longest_str)
                {
                    longest_str = emp->name.size();
                } 
            }
            Q.pop();
        }

        // Prity drawing
        // unsigned long len = (longest_str - 3)/2;
        output << '\n'
               << string((longest_str - 3)/2, ' ') << "p\\c" << string(longest_str - (longest_str - 3)/2 -2, ' ')<< '|';
        
        Q.push(new_data.root);
        while (!Q.empty())
        {
            emp = Q.front();
            for(worker* sub : emp->his_workers){
                Q.push(sub);

            }
            // varifiying that child is not root
            if(!emp->supirior_name.empty()){
                output <<string((longest_str - emp->name.size())/2, ' ') << emp->name 
                    << string((longest_str - emp->name.size())/2 + 1, ' ') << '|';
            }
            Q.pop();
        }
        output << '\n' << string((longest_str + 2) * (new_data.size), '-') << '\n';
        
        Q.push(new_data.root);
        while (!Q.empty())
        {
            emp = Q.front();
            output << string((longest_str - emp->name.size())/2, ' ') << emp->name 
                << string((longest_str - emp->name.size())/2 + 1, ' ') << '|';
            
            for(worker* sub : emp->his_workers){
                Q.push(sub);
                // varifiying that child is not root
                if(!sub->supirior_name.empty()){
                    pair<string, string> pos = {emp->name, sub->name};
                    output << string(longest_str / 2, ' ') << mat.at(pos) 
                        << string(longest_str - (longest_str / 2), ' ') << '|';
                }
            }
            output << "\n";
            // output << "\n" << string((longest_str + 2) * (new_data.employees.size()), '-') << '\n';

            Q.pop();
        }
        
        return output << '\n';
    }

    // // Operators
    // ostream &operator<<(ostream &output, OrgChart &new_data)
    // {
    //     // string *level_order_it = new_data.begin_level_order();
    //     int size = new_data.size;
    //     map<pair<string, string>, int> mat;
    //     unsigned long longest_str = 0;

    //     // Find the longest name & fill the mat --> if a is b's subordinate than mat(a,b) = 1 else mat(a,b) = 0.
    //     for (worker& perent : new_data.employees)
    //     {
    //         for (worker& child : new_data.employees)
    //         {
    //             if(child.supirior_name.size() > 0){
    //                 pair<string, string> temp = {perent.name, child.name};
    //                 mat[temp] = 0;
    //                 if (perent.name.size() > longest_str || child.name.size() > longest_str)
    //                 {
    //                     longest_str = perent.name.size() > child.name.size() ? perent.name.size() : child.name.size();
    //                 }
    //                 if (child.supirior_name == perent.name)
    //                 {
    //                     // cout << "perent = " << perent.name << " child = " << child.name << " child parent = "<< child.supirior << "\n";
    //                     mat[temp] = 1;
    //                 }
    //             }
    //         }
    //     }

    //     // Prity drawing
    //     // unsigned long len = (longest_str - 3)/2;
    //     output << '\n'
    //            << string((longest_str - 3)/2, ' ') << "p\\c" << string(longest_str - (longest_str - 3)/2 -2, ' ')<< '|';
    //     for (worker& emp : new_data.employees)
    //     {
    //         // varifiying that child is not root
    //         if(emp.supirior_name.size() > 0){
    //             output <<string((longest_str - emp.name.size())/2, ' ') << emp.name << string((longest_str - emp.name.size())/2 + 1, ' ') << '|';
    //         }
    //     }
    //     output << '\n'
    //            << string((longest_str + 2) * (new_data.employees.size()), '-') << '\n';
    //     for (worker& perent : new_data.employees)
    //     {
    //         output << string((longest_str - perent.name.size())/2, ' ') << perent.name << string((longest_str - perent.name.size())/2 + 1, ' ') << '|';
    //         for (worker& child : new_data.employees)
    //         {
    //             // varifiying that child is not root
    //             if(child.supirior_name.size() > 0){
    //                 pair<string, string> pos = {perent.name, child.name};
    //                 output << string(longest_str / 2, ' ') << mat.at(pos) << string(longest_str - (longest_str / 2), ' ') << '|';
    //             }
    //         }
    //         output << "\n";
    //         // output << "\n" << string((longest_str + 2) * (new_data.employees.size()), '-') << '\n';
    //     }
    //     return output << '\n';
    // }

}