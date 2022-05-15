
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
      .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

    cout << "im here 1\n";
    fflush(stdout);

    string* level = organization.begin_level_order();


    // cout << organization.end()[0]<< '\n' << " im here 2\n";
    // fflush(stdout);

    for (worker& emp : organization.get_employees())
    {
        cout << emp.his_workers.size() << " ";
    }


    // for (worker& emp : organization.get_employees())
    // {
    //     cout << emp.name << " ";
    // }

    for (p_worker emp : organization.get_print_prity())
    {
        cout << emp->name << " ";
    }
    
    // cout << organization;
    // for (int i = 0; i < organization.get_size(); i++)
    // {
    //     cout << level[i] << " ";
    // }
    

    // string a[3];
    // a[0] = "aaa";
    // a[1] = "bbb";
    // a[2] = "ccc";
    // string* b = a;
    // cout << b[2] << "\n";

}