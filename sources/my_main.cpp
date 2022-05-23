
#include <string>
#include <string.h>
#include <iostream>

#include "OrgChart.hpp"

// How to run:
// g++ OrgChart.cpp my_iterator.cpp my_main.cpp my_iterator.hpp OrgChart.hpp

using namespace std;
using namespace ariel;

OrgChart chart;
string name;
string name1;
string name2;

void get_name_from_user()
{
    name.clear();
    getline(cin,name);
    cout << "The name entered is: " << name << "\n";
}

void action(int act){
        // cout << "========================================================";
        // cout << "\nEnter an action num:\n"
        // << "0: exit\n1: add_root , 2: add_sub \n"
        // << "3: print_level_order , 4: print_pre_order\n"
        // << "5: print_reverse_order \n6: print_chart\n";

    switch (act){
        case 0:
            exit(0);
        case 1:
            cout << "Enter a name\n";
            get_name_from_user();
            chart.add_root(name);
            cout << "Root updated successfully!\n";
            break;
        case 2:
            cout << "Enter a supirior name\n";
            get_name_from_user();
            name1 = name;
            cout << "Enter a subordinate name\n";
            get_name_from_user();
            name2 = name;
            chart.add_sub(name1,name2);
            cout << "Sub updated successfully!\n";
            break;
        case 3:
            for (auto i = chart.begin_level_order(); i != chart.end_level_order(); ++i)
            {
                cout << *i << " ";
            }
            cout << "\n";
            break;
        case 4:
            for (auto i = chart.begin_preorder(); i != chart.end_preorder(); ++i)
            {
                cout << *i << " ";
            }
            cout << "\n";
            break;
        case 5:
            for (auto i = chart.begin_reverse_order(); i != chart.reverse_order(); ++i)
            {
                cout << *i << " ";
            }
            cout << "\n";
            break;
        case 6:
            cout << chart;
            break;
        
        default:
            cout << "Chose a num between 0 - 6\n";
            break;
        }
}


int main(){
    
    OrgChart a;
    a.add_root("CEO")
        .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

    OrgChart b;
    b = a;
    for (auto i = a.begin_level_order(); i != a.end_level_order(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n";
    for (auto i = b.begin_level_order(); i != b.end_level_order(); ++i)
    {
        cout << *i << " ";
    }




    // int act;

    // while (1)
    // {
    //     // Get the desired operation
    //     cout << "========================================================";
    //     cout << "\nEnter an action num:\n"
    //     << "0: exit\n1: add_root , 2: add_sub \n"
    //     << "3: print_level_order , 4: print_pre_order\n"
    //     << "5: print_reverse_order \n6: print_chart\n";
        
    //     fflush(stdin);
    //     cin >> act;
    //     fflush(stdin);
    //     getline(cin, name1);

    //     // If needed a second matrix get it too
    //     try{
    //         // Do the operation
    //         action(act);
    //     }
    //     catch(const std::exception& e){
    //         cout<< "Function " << act <<  " throw us out! " << e.what() << " Try something else..\n";
    //         fflush(stdout);
    //     }
    // }

    return 0;
}
