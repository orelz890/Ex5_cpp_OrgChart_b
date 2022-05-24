// In this part i was aided by this site for level/reverse/pre order:
// https://www.geeksforgeeks.org/reverse-level-order-traversal


#include "OrgChart.hpp"
#include <unistd.h>

namespace ariel
{
    OrgChart::OrgChart()
    {
        this->size = 0;
        this->root = NULL;
        this->reverse_root = NULL;
    }

    OrgChart::OrgChart(const OrgChart& other) : OrgChart()
    {
        *this = other;
    }


    OrgChart::OrgChart(OrgChart&& other) noexcept : OrgChart()
    {
        *this = std::move(other);
    }


    OrgChart::~OrgChart()
    {
        this->level_order_tree();
        employee* emp = this->root;
        employee* temp = NULL;
        while (emp != NULL)
        {
            temp = emp->next_in_line;
            delete emp;
            emp = temp;
        }
    }

    OrgChart& OrgChart::operator=(OrgChart&& other) noexcept
    {
        *this = std::move(other);
        return *this;
    }

    OrgChart& OrgChart::operator=(const OrgChart& other)
    {
        if (&other != this)
        {
            // Delete old data
            if (this->root != NULL)
            {
                this->~OrgChart();
            }
            // Zero the chart
            this->size = 0;
            this->root = NULL;
            this->reverse_root = NULL;

            // Input the new data
            if (other.size > 0)
            {
                std::queue<employee*> Q;
                Q.push(other.root);
                employee* supirior = NULL;
                while (!Q.empty())
                {
                    supirior = Q.front();
                    // Add the root first
                    if (supirior->name == other.root->name)
                    {
                        this->add_root(supirior->name);
                    }
                    for (size_t j = 0; j < supirior->his_emps.size(); j++)
                    {
                        // Add the subordinates of every supirior
                        this->add_sub(supirior->name,supirior->his_emps.at((unsigned long)j)->name);
                        Q.push(supirior->his_emps.at((unsigned long)j));
                    }
                    Q.pop();
                }
            }
        }
        return *this;
    }


    bool is_empty(std::string& a){
        if (a.empty())
        {
            throw std::runtime_error("The input is empty!");
        }
        bool flag = false;
        for (char& c : a)
        {
            if (c != ' ')
            {
                flag = true;
            }
        }
        if (!flag)
        {
            throw std::runtime_error("The name should not contain only spaces..");
        }
        
        return a.empty();
    }
    // Funcs
    OrgChart& OrgChart::add_root(std::string supirior_name)
    {
        is_empty(supirior_name);
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

    OrgChart& OrgChart::add_sub(std::string supirior_name, std::string new_emp_name)
    {
        // Check validity
        is_empty(supirior_name);
        is_empty(new_emp_name);
        if (this->root == NULL)
        {
            throw std::runtime_error("can't add sub before root");
        }
        bool legal = false;
        if (this->root->name != supirior_name)
        {
            bool flag = true;
            std::queue<employee*> Q;

            // Enter the root(first element) to the queue
            Q.push(this->root);
            employee* sup = NULL;
            employee* sub = NULL;
            while (!Q.empty() && flag)
            {
                sup = Q.front();
                if (!sup->his_emps.empty())
                {
                    // Add the current supirior emps to the queue
                    for (unsigned long i = 0; i < sup->his_emps.size(); i++){
                        sub = sup->his_emps.at(i);
                        Q.push(sub);
                        // Check if the current subordinate is the supirioir of our new emp
                        if (sub->name == supirior_name)
                        {
                            // Creat the new emp node and add it to his supirior emps
                            legal = true;
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
            // Creat the new emp node and add it to root emps
            legal = true;
            employee* new_emp = new employee(new_emp_name,this->root);
            this->root->his_emps.push_back(new_emp);
            this->size++;
        }

        // If legal is still false it means we didn't add a new member to the chart therefore, throw exeption.. 
        if (!legal)
        {
            throw std::runtime_error("employer doesn't exist");
        }
        
        return *this;
    }

    // For every node assign his next element in a level order mathod
    void OrgChart::level_order_tree()
    {
        employee* last_emp = NULL;
        int i = 0;
        if (this->size > 0)
        {
            std::queue<employee*> Q;
            Q.push(this->root);
            employee* supirior = NULL;
            while (!Q.empty())
            {
                supirior = Q.front();
                // Set the curent node next element
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL; 
                // Add the current supirior emps to the queue
                for (size_t j = 0; j < supirior->his_emps.size(); j++)
                {
                    Q.push(supirior->his_emps.at((unsigned long)j));
                }
                Q.pop();
            }
        }
    }

    // For every node assign his next element in a pre_order mathod
    void OrgChart::pre_order_tree()
    {
        employee* last_emp = NULL;
        std::stack<employee*> S;
        if (this->size > 0)
        {
            // Add the root to the stack             
            S.push(this->root);
            employee* supirior = NULL;
            while (!S.empty())
            {
                // Set the current node next element
                supirior = S.top();
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL;
                S.pop();
                // Add the current supirior emps to the stack
                for (int j = (int)supirior->his_emps.size() - 1; j >= 0; j--)
                {
                    S.push(supirior->his_emps.at((unsigned int)j));
                }
            }
        }

    }

    // For every node assign his next element in a reverse order mathod
    void OrgChart::reverse_order_tree()
    {
        if (this->size > 0)
        {        
            employee* last_emp = NULL;
            this->reverse_root = NULL;
            employee* supirior = NULL;
            
            std::stack<employee*> S;
            std::queue<employee*> Q;
            
            // Add the root to the queue
            Q.push(this->root);

            while (!Q.empty())
            {
                supirior = Q.front();
                Q.pop();
                // Add the current supirior to the stack
                S.push(supirior);
                // Add his emps to the queue
                for (int j = (int)supirior->his_emps.size() - 1; j >= 0; j--)
                {
                    Q.push(supirior->his_emps.at((unsigned int)j));
                }
            }
            // Now we have a stack filled with all of our emps, but when we pop an element the last element added will be poped..
            while (!S.empty())
            {
                supirior = S.top();
                // set the new root as the first element poped
                if (this->reverse_root == NULL)
                {
                    this->reverse_root = supirior;
                }
                // Set every node next element                
                if (last_emp != NULL)
                {
                    last_emp->next_in_line = supirior;
                }
                last_emp = supirior;
                last_emp->next_in_line = NULL;
                S.pop();
            }
        }

    }

    // Iterators
    my_iterator<std::string> OrgChart::begin()
    {
        return begin_level_order();
    }

    my_iterator<std::string> OrgChart::end()
    {
        return end_level_order();
    }

    my_iterator<std::string> OrgChart::begin_level_order()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        }
        this->level_order_tree();
        return my_iterator<std::string>{this->root};
    }

    my_iterator<std::string> OrgChart::end_level_order()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        }
        return my_iterator<std::string>{};
    }

    my_iterator<std::string> OrgChart::begin_reverse_order()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        }
        this->reverse_order_tree();
        return my_iterator<std::string>{this->reverse_root};
    }

    my_iterator<std::string> OrgChart::reverse_order()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        }
        return my_iterator<std::string>{};
    }

    my_iterator<std::string> OrgChart::begin_preorder()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        }
        this->pre_order_tree();
        return my_iterator<std::string>{this->root};
    }

    my_iterator<std::string> OrgChart::end_preorder()
    {
        if (this->root == NULL)
        {
            throw std::runtime_error("chart is empty!");
        } 
        return my_iterator<std::string>{};
    }

    // Operators
    std::ostream &operator<<(std::ostream &output, OrgChart &new_data)
    {
        
        if (new_data.root == NULL)
        {
            throw std::runtime_error("Can't print an empty chart..");
        }
        
        // string *level_order_it = new_data.begin_level_order();
        std::map<std::pair<std::string, std::string>, int> mat;
        unsigned long longest_str = 0;
        std::vector<std::string> all_emps;

        // Find the longest name & fill the mat --> if a is b's subordinate than mat(a,b) = 1 else mat(a,b) = 0.
        std::queue<employee*> Q;
        Q.push(new_data.root);
        employee* emp = NULL;
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

        // Pretty drawing
        output << '\n' << "p\\c" << std::string(longest_str - 3, ' ') << "|";
        for (std::string& sup : all_emps)
        {
            if (sup != new_data.root->name)
            {
                std::cout << sup << "|";
            }
           
            for (std::string& sub : all_emps)
            {
                std::pair<std::string,std::string> key = {sup,sub};
                mat[key] = 0;
            }
        }
        
        int count_chars = 0;
        Q.push(new_data.root);
        while (!Q.empty())
        {
            emp = Q.front();
            for(employee* sub : emp->his_emps){
                Q.push(sub);
                count_chars += (int)sub->name.length() + 1;
                std::pair<std::string, std::string> key = {emp->name, sub->name};
                mat[key] = 1;
            }
            Q.pop();
        }
        count_chars += (int)longest_str + 1;
        output << '\n' << std::string((unsigned long)count_chars, '-') << '\n';
        
        for (std::string& sup : all_emps)
        {
            output << sup << std::string(longest_str - sup.length() , ' ') << '|';

            for (std::string& sub : all_emps)
            {
                if (sub != new_data.root->name)
                {
                    std::pair<std::string, std::string> pos = {sup,sub};
                    if (sub.length()%2 == 0)
                    {
                        output << std::string((sub.length()) / 2 - 1, ' ') << mat.at(pos)
                            << std::string((sub.length()) / 2, ' ') << '|';
                    }
                    else
                    {
                        output << std::string((sub.length()) / 2, ' ') << mat.at(pos)
                            << std::string((sub.length()) / 2, ' ') << '|';
                    }
                }
                
            }
            output << "\n" << std::string((unsigned long)count_chars, '-') << '\n';            
        }
        
        return output << '\n';
    }

}