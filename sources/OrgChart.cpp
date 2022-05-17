// In this part i was aided by this site:
// https://www.geeksforgeeks.org/reverse-level-order-traversal

#include "OrgChart.hpp"

namespace ariel
{
    OrgChart::OrgChart()
    {
        this->employees.clear();
        int longest_str = 0;
        string* level_order_it = NULL;
        string* pre_order_it = NULL;
        string* reverse_order_it = NULL;
    }

    OrgChart::~OrgChart(){
        
    }

    // Funcs
    OrgChart& OrgChart::add_root(string supirior_name)
    {
        string temp;
        if (this->employees.empty())
        {
            this->employees.emplace_back(worker{supirior_name,temp});
        }
        else
        {
            this->employees.at(0).name = supirior_name;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(string supirior, string new_emp)
    {
        for (int i = 0; i < this->get_size(); i++)
        {
            if (this->employees.at(i).name == supirior)
            {
                int last_element = this->get_size();
                this->employees.emplace_back(worker{new_emp, supirior});
                this->employees.at(i).his_workers.emplace_back(&(this->employees.at(last_element)));
                // cout << this->employees.at(i).name << " is " << this->employees.at(last_element).name
                //      << "'s supirior and he has: " << this->employees.at(i).his_workers.size() << " subordinates:\n";
                break;
            }
        }
        return *this;
    }

    void OrgChart::level_order_tree(){
        string ans[employees.size()];
        vector<p_worker> new_order;
        int i = 0;
        if (!employees.empty())
        {
            queue<p_worker> Q;
            Q.push(&this->employees.at(0));

            while (!Q.empty())
            {
                p_worker supirior = Q.front();
                new_order.emplace_back(supirior);
                ans[i++] = supirior->name;
                cout << "curr child = " << supirior->name << " and he has " << supirior->his_workers.size() << " childs\n"; 
                for (int j = 0; j < supirior->his_workers.size(); j++)
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
        string ans[employees.size()];
        vector<p_worker> new_order;

        int i = 0;
        stack<p_worker> S;
        S.push(&this->employees.at(0));
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

    void OrgChart::reverse_order_tree(){
        string ans[employees.size()];
        vector<p_worker> new_order;

        int i = 0;
        p_worker supirior;
        stack<p_worker> S;
        queue<p_worker> Q;
        Q.push(&this->employees.at(0));

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
        return my_iterator<string>{this->employees};
    }

    my_iterator<string> OrgChart::end_level_order()
    {
        return my_iterator<string>{};
    }

    my_iterator<string> OrgChart::begin_reverse_order()
    {
        this->reverse_order_tree();
        return my_iterator<string>{this->employees};
    }

    my_iterator<string> OrgChart::reverse_order()
    {
        return my_iterator<string>{};
    }

    my_iterator<string> OrgChart::begin_preorder()
    {
        this->pre_order_tree();
        return my_iterator<string>{this->employees};
    }

    my_iterator<string> OrgChart::end_preorder()
    {
        return my_iterator<string>{};
    }

    // Operators
    ostream &operator<<(ostream &output, OrgChart &new_data)
    {
        // string *level_order_it = new_data.begin_level_order();
        int size = new_data.employees.size();
        map<pair<string, string>, int> mat;
        int longest_str = 0;

        // Find the longest name & fill the mat --> if a is b's subordinate than mat(a,b) = 1 else mat(a,b) = 0.
        for (worker& perent : new_data.employees)
        {
            for (worker& child : new_data.employees)
            {
                if(child.supirior.size() > 0){
                    pair<string, string> temp = {perent.name, child.name};
                    mat[temp] = 0;
                    if (perent.name.size() > longest_str || child.name.size() > longest_str)
                    {
                        longest_str = perent.name.size() > child.name.size() ? perent.name.size() : child.name.size();
                    }
                    if (child.supirior == perent.name)
                    {
                        // cout << "perent = " << perent.name << " child = " << child.name << " child parent = "<< child.supirior << "\n";
                        mat[temp] = 1;
                    }
                }
            }
        }

        // Prity drawing
        output << '\n'
               << string((longest_str - 3)/2, ' ') << "p\\c" << string(longest_str- (longest_str - 3)/2 -2, ' ')<< '|';
        for (worker& emp : new_data.employees)
        {
            // varifiying that child is not root
            if(emp.supirior.size() > 0){
                output <<string((longest_str - emp.name.size())/2, ' ') << emp.name << string((longest_str - emp.name.size())/2 + 1, ' ') << '|';
            }
        }
        output << '\n'
               << string((longest_str + 2) * (new_data.employees.size()), '-') << '\n';
        for (worker& perent : new_data.employees)
        {
            output << string((longest_str - perent.name.size())/2, ' ') << perent.name << string((longest_str - perent.name.size())/2 + 1, ' ') << '|';
            for (worker& child : new_data.employees)
            {
                // varifiying that child is not root
                if(child.supirior.size() > 0){
                    pair<string, string> pos = {perent.name, child.name};
                    output << string(longest_str / 2, ' ') << mat.at(pos) << string(longest_str - (longest_str / 2), ' ') << '|';
                }
            }
            output << "\n";
            // output << "\n" << string((longest_str + 2) * (new_data.employees.size()), '-') << '\n';
        }
        return output << '\n';
    }

}
