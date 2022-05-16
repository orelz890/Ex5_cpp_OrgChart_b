// In this part i was aided by this site:
// https://www.geeksforgeeks.org/reverse-level-order-traversal

#include "OrgChart.hpp"

namespace ariel
{
    OrgChart::OrgChart()
    {
        this->root = NULL;
    }

    // Funcs
    OrgChart& OrgChart::add_root(string supirior_name)
    {

        worker new_emp;
        new_emp.name = supirior_name;

        if (this->employees.empty())
        {
            employees.emplace_back(new_emp);
        }
        else
        {
            new_emp.his_workers = this->employees.at(0).his_workers;
            this->employees.at(0) = new_emp;
        }
        this->root = &this->employees.at(0);
        cout << this->root->name << " is the root now and the size is: " << this->get_size() << "\n";
        return *this;
    }

    OrgChart& OrgChart::add_sub(string supirior, string new_emp)
    {
        worker temp;
        temp.name = new_emp;

        for (int i = 0; i < this->get_size(); i++)
        {
            if (this->employees.at(i).name == supirior)
            {
                this->employees.emplace_back(temp);
                this->employees.at(this->get_size() - 1).supirior = this->employees.at(i).name;
                this->employees.at(i).his_workers.emplace_back(&(this->employees.at(this->get_size() - 1)));
                cout << this->employees.at(i).name << " is " << new_emp << "'s supirior and he has: " << this->employees.at(i).his_workers.size() << " subordinates:\n";
            }  
        }    
        return *this;
    }

    // Iterators
    string *OrgChart::begin()
    {
        return begin_level_order();
    }

    string *OrgChart::end()
    {
        return end_level_order();
    }

    string *OrgChart::begin_level_order()
    {
        string ans[employees.size()];
        int i = 0;
        if (!employees.empty())
        {
            queue<p_worker> Q;
            Q.push(&this->employees.at(0));

            while (!Q.empty())
            {
                p_worker supirior = Q.front();
                ans[i++] = supirior->name;
                cout << supirior->name << " has: " << supirior->his_workers.size() << " workers under him:\n";
                fflush(stdout);

                for (int j = 0; j < supirior->his_workers.size(); j++)
                {
                    cout << supirior->his_workers.at(j)->name << "\n";
                    fflush(stdout);
                    Q.push(supirior->his_workers.at(j));
                }
                Q.pop();
            }
        }
        this->level_order_it = ans;
        return this->level_order_it;
    }

    string *OrgChart::end_level_order()
    {
        return &(begin_level_order()[employees.size() - 1]);
    }

    string *OrgChart::begin_reverse_order()
    {
        // string ans[employees.size()];
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
            this->reverse_order_it[i++] = supirior->name;
            S.pop();
        }

        return this->reverse_order_it;
    }

    string *OrgChart::reverse_order()
    {
        return &(begin_reverse_order()[employees.size() - 1]);
    }

    string *OrgChart::begin_preorder()
    {
        // string ans[employees.size()];
        int i = 0;
        stack<p_worker> S;
        S.push(&this->employees.at(0));
        while (!S.empty())
        {
            p_worker supirior = S.top();
            this->pre_order_it[i++] = supirior->name;
            S.pop();
            for (int j = supirior->his_workers.size() - 1; j >= 0; j--)
            {
                S.push(supirior->his_workers.at((unsigned int)j));
            }
        }
        return this->pre_order_it;
    }

    string *OrgChart::end_preorder()
    {
        return &(begin_preorder()[employees.size() - 1]);
    }

    // Operators
    ostream &operator<<(ostream &output, OrgChart &new_data)
    {
        // string *level_order_it = new_data.begin_level_order();
        int size = new_data.employees.size();
        map<pair<string, string>, int> mat;
        int longest_str = 0;

        // Init the mat with zeros & find the longest name
        for (worker& perent : new_data.employees)
        {
            for (worker& child : new_data.employees)
            {
                pair<string, string> temp = {perent.name, child.name};
                mat[temp] = 0;
                if (perent.name.size() > longest_str || child.name.size() > longest_str)
                {
                    longest_str = perent.name.size() > child.name.size() ? perent.name.size() : child.name.size();
                }
            }
        }
        // Fill the mat --> if a is b's subordinate than mat(a,b) = 1
        for (worker& perent : new_data.employees)
        {
            for (worker& child : new_data.employees)
            {
                pair<string, string> temp = {perent.name, child.name};
                if (child.supirior == perent.name)
                {
                    cout << "perent = " << perent.name << " child = " << child.name << "child parent = "<< child.supirior << "\n";
                    mat[temp] = 1;
                }
            }
        }
        // Prity drawing
        output << '\n'
               << string((longest_str - 3)/2, ' ') << "p\\c" << string(longest_str- (longest_str - 3)/2 -3, ' ')<< '|';
        for (worker& emp : new_data.employees)
        {
            output << emp.name << string(longest_str - emp.name.size() + 1, ' ') << '|';
        }
        output << '\n'
               << string((longest_str + 3) * (new_data.employees.size() + 2), '-') << '\n';
        for (worker& perent : new_data.employees)
        {
            output << perent.name << string(longest_str - perent.name.size(), ' ') << '|';
            for (worker& child : new_data.employees)
            {
                pair<string, string> pos = {perent.name, child.name};
                output << string(longest_str / 2, ' ') << mat.at(pos) << string(longest_str - (longest_str / 2), ' ') << '|';
            }
            output << '\n';
        }
        return output;
    }

}