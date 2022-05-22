
// #include <string>
// #include <string.h>
// #include <iostream>

// #include "OrgChart.hpp"

// using namespace std;
// using namespace ariel;
// int main(){

//     OrgChart organization;
//     organization.add_root("CEO")
//       .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
//       .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
//       .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
//       .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
//       .add_sub("COO", "VP_BI")      // Now the VP_BI is subordinate to the COO
//       .add_sub("CTO", "AAA")
//       .add_sub("AAA","BBB");

//     cout << "im in main\n";
//     fflush(stdout);

//     // // prints tree representation (matrix)
//     cout << organization;

//     // int g = 0;
//     // cout << "\n\nroot nane == "<< organization.get_root()->name << " and his emps are:\n";
//     // for (employee* e : organization.get_root()->his_emps)
//     // {
//     //     cout << g++ << ") " << e->name << "\n";
//     // }
    

//     my_iterator<string> it= organization.begin();

//     // cout << *it << " ";
//     // cout << *it++ << " " << *it << " ";

//     // vector<worker> employees;
//     // worker a;
//     // a.name = "aa";
//     // worker b;
//     // b.name = "bb";
//     // employees.emplace_back(a);
//     // employees.emplace_back(b);

//     // employees.at(0).his_workers.emplace_back(&b);
//     // cout<< employees.at(0).his_workers.at(0)->name;
    

//     // string a[3];
//     // a[0] = "aaa";
//     // a[1] = "bbb";
//     // a[2] = "ccc";
//     // string* b = a;
//     // cout << b[2] << "\n";

// }