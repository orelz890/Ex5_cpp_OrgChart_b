
// #include <string>
// #include <string.h>
// #include <iostream>

// #include "OrgChart.hpp"

// // How to run:
// // g++ OrgChart.cpp my_iterator.cpp my_main.cpp my_iterator.hpp OrgChart.hpp

// using namespace std;
// using namespace ariel;
// int main(){
//     //create object person for this test
//     class Person {
//     public:
//         string name;
//         int age;

//         Person(string Name, int Age) : name(Name), age(Age) {}

//         bool operator==(Person &p1) {
//             return this->name == p1.name;
//         }
//     };
//     //instantiate People
//     Person Great_GrandFather("Great_GrandFather", 85);
//     Person Grandfather("GrandFather", 65);
//     Person Father("Father", 45);
//     Person Uncle("Uncle", 43);
//     Person Aunt("Aunt", 43);
//     Person Son("Son", 20);
//     Person Daughter("Daughter", 18);
//     Person Cousin("Cousin", 15);

//     OrgChart chart1;
//     chart1.add_root(Aunt.name);
//     chart1.add_root(Great_GrandFather.name);
//     chart1.add_sub(Great_GrandFather.name, Grandfather.name);
//     chart1.add_sub(Grandfather.name, Father.name);
//     chart1.add_sub(Grandfather.name, Uncle.name);
//     chart1.add_sub(Grandfather.name, Aunt.name);
//     chart1.add_sub(Father.name, Son.name);
//     chart1.add_sub(Father.name, Daughter.name);
//     chart1.add_sub(Uncle.name, Cousin.name);

//     cout << chart1;
//     // test level order
//     for (auto it = chart1.begin_level_order(); it != chart1.end_level_order(); ++it) {
//         cout << *it << " ";
//     }
//     cout << '\n';

//     //add another field and check that it works
//     Person Cousin2("Cousin2", 14);
//     chart1.add_sub(Aunt.name, Cousin2.name);

//     //add another field and check that it works
//     Person GreatUncle("GreatUncle", 62);
//     chart1.add_sub(Great_GrandFather.name, GreatUncle.name);

//     // test reverse level order
//     for (auto it = chart1.begin_reverse_order(); it != chart1.reverse_order(); ++it) {
//         cout << *it << " ";
//     }
//     cout << '\n';

// }