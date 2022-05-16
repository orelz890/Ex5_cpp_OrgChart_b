
#include <string>
#include <string.h>
#include <iostream>

#include "OrgChart.hpp"

using namespace std;
using namespace ariel;
int main(){

    OrgChart organization;
    organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI")      // Now the VP_BI is subordinate to the COO
      .add_sub("CEO", "AAA")
      .add_sub("CEO", "BBB");
    // organization.add_root("CEO")
    // .add_sub("CEO", "CTO")
    // .add_sub("CEO", "CFO")
    // .add_sub("CEO", "COO")
    // .add_sub("CEO", "AAA")
    // .add_sub("CEO", "BBB");
    
    cout<< organization.get_employees().at(0).his_workers.at(0)->name << "\n\n";
    cout << "im in main\n";
    fflush(stdout);

    string* level = organization.begin_level_order();
    // for (int i = 0; i < organization.get_size(); i++)
    // {
    //     cout << level[i] << " ";
    // }
    
    // cout << organization.end()[0]<< '\n' << " im here 2\n";
    // fflush(stdout);

    int g;

    for (worker& emp : organization.get_employees())
    {
        cout << emp.his_workers.size() << " ";
    }

    for (worker& emp : organization.get_employees())
    {
        cout<< "emp.name = " <<  emp.name << " childrens:\n";
        g = 0;
        for (int j = 0; j < emp.his_workers.size(); j++)
        {
            cout << g++ << ") " << emp.his_workers.at(j)->name << "\n";
        }
    }
    cout << organization;

    // vector<worker> employees;
    // worker a;
    // a.name = "aa";
    // worker b;
    // b.name = "bb";
    // employees.emplace_back(a);
    // employees.emplace_back(b);

    // employees.at(0).his_workers.emplace_back(&b);
    // cout<< employees.at(0).his_workers.at(0)->name;
    

    // string a[3];
    // a[0] = "aaa";
    // a[1] = "bbb";
    // a[2] = "ccc";
    // string* b = a;
    // cout << b[2] << "\n";

}