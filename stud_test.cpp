// // g++ -o a.out OrgChart.cpp OrgChart.hpp my_iterator.cpp my_iterator.hpp stud_test.cpp doctest.h 


// #include "doctest.h"
// #include <string>
// #include <stdexcept>
// #include <iostream>
// #include <vector>
// #include "OrgChart.hpp"
// using namespace std;
// using namespace ariel;

// TEST_CASE("A child who has no father")
// {
//     OrgChart organization;
//     organization.add_root("CEO")
//         .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
//         .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
//         .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
//         .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
//         .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO

//     //   cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
//     //        CEO
//     //        |--------|--------|
//     //        CTO      CFO      COO
//     //        |                 |
//     //        VP_SW             VP_BI
//     //  */


//     CHECK_NOTHROW(organization.add_sub("VP_BI", "New Employee"));
//     CHECK_THROWS(organization.add_sub("ME", "New Employee"));
//     CHECK_NOTHROW(organization.add_root("ME"));
//     CHECK_NOTHROW(organization.add_sub("ME", "New Employee"));
// }
// TEST_CASE("Org 1")
// {
//     vector<string> names = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])  // Now the CTO is subordinate to the CEO
//         .add_sub(names[0], names[2])  // Now the CFO is subordinate to the CEO
//         .add_sub(names[0], names[3])  // Now the COO is subordinate to the CEO
//         .add_sub(names[1], names[4])  // Now the VP Software is subordinate to the CTO
//         .add_sub(names[3], names[5]); // Now the VP_BI is subordinate to the COO
//     //        CEO
//     //        |--------|--------|
//     //        CTO      CFO      COO
//     //        |                 |
//     //        VP_SW             VP_BI
//     //  */
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be: CEO CTO CFO COO VP_SW VP_BI
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be: VP_SW VP_BI CTO CFO COO CEO
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to be: CEO CTO VP_SW CFO COO VP_BI
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be: CEO CTO CFO COO VP_SW VP_BI
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be: 3 3 3 3 5 5
// }

// TEST_CASE("Org 2")
// {
//     vector<string> names = {"grandfather", "father", "uncle", "mother", "boy", "girl"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }

// TEST_CASE("Org 3")
// {
//     vector<string> names = {"rector", "dean", "department head", "lecture", "practitioner", "student"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 4")
// {
//     vector<string> names = {"computer", "Hard Disk", "Graphics Card", "keyboard", "bits", "buttons"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 5")
// {
//     vector<string> names = {"house", "kitchen", "bedroom", "living room", "oven", "couch"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 6")
// {
//     vector<string> names = {"The Milky Way", "Earth", "Venus", "Mars", "Israel", "Meridiani Planum"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 7")
// {
//     vector<string> names = {"Mor", "Arhel", "Haim", "Nofar", "Tal", "Yavgni"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 8")
// {
//     vector<string> names = {"Dvir Gev", "Dvir Biton", "Raz", "Amit", "Ariel", "Aviad"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 9")
// {
//     vector<string> names = {"Rick", "Morty", "Summer", "Beth", "Jerry", "Mr. Meeseeks"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }
// TEST_CASE("Org 10")
// {
//     vector<string> names = {"Bulbasaur", "Charmander", "Squirtle", "Caterpie", "Weedle", "Pidgey"};
//     vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
//     vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
//     vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
//     OrgChart organization;
//     organization.add_root(names[0])
//         .add_sub(names[0], names[1])
//         .add_sub(names[0], names[2])
//         .add_sub(names[0], names[3])
//         .add_sub(names[1], names[4])
//         .add_sub(names[3], names[5]);
//     size_t i = 0;
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++], (*it));
//     } // Needs to be like exp_level_order
//     i = 0;
//     for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//     {
//         CHECK_EQ(exp_reverse_order[i++], (*it));
//     } // Needs to be like exp_reverse_order
//     i = 0;
//     for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
//     {
//         CHECK_EQ(exp_preorder[i++], (*it));
//     } // Needs to belike exp_preorder
//     i = 0;
//     for (auto element : organization)
//     { // this should work like level order
//         CHECK_EQ(exp_level_order[i++], element);
//     } // Needs to be like exp_level_order
//     i = 0;
//     // demonstrate the arrow operator:
//     for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     {
//         CHECK_EQ(exp_level_order[i++].size(), it->size());
//     } // Needs to be like exp_level_order
// }

// // //
// // // Created by shaul on 09/05/2022.
// // //
// // #include "doctest.h"
// // #include "OrgChart.hpp"
// // #include "string"
// // using namespace ariel;
// // using namespace std;
// // TEST_CASE ("Case 1 - Family tree")
// // {
// //     //create object person for this test
// //     class Person {
// //     public:
// //         string name;
// //         int age;

// //         Person(string Name, int Age) : name(Name), age(Age) {}

// //         bool operator==(Person &p1) {
// //             return this->name == p1.name;
// //         }
// //     };
// //     //instantiate People
// //     Person Great_GrandFather("Great_GrandFather", 85);
// //     Person Grandfather("GrandFather", 65);
// //     Person Father("Father", 45);
// //     Person Uncle("Uncle", 43);
// //     Person Aunt("Aunt", 43);
// //     Person Son("Son", 20);
// //     Person Daughter("Daughter", 18);
// //     Person Cousin("Cousin", 15);

// //     OrgChart chart1;
// //             CHECK_THROWS(chart1.add_sub(Aunt.name, Son.name));//no root
// //             CHECK_NOTHROW(chart1.add_root(Aunt.name));
// //             CHECK_NOTHROW(chart1.add_root(Great_GrandFather.name));
// //             CHECK_THROWS(chart1.add_sub(Aunt.name, Son.name));//root was replaced
// //             CHECK_THROWS(chart1.add_sub(Son.name, Uncle.name));//no such value
// //             CHECK_NOTHROW(chart1.add_sub(Great_GrandFather.name, Grandfather.name));
// //             CHECK_NOTHROW(chart1.add_sub(Grandfather.name, Father.name));
// //             CHECK_NOTHROW(chart1.add_sub(Grandfather.name, Uncle.name));
// //             CHECK_NOTHROW(chart1.add_sub(Grandfather.name, Aunt.name));
// //             CHECK_THROWS(chart1.add_sub(Cousin.name, Father.name));//cousin not added yet
// //             CHECK_NOTHROW(chart1.add_sub(Father.name, Son.name));
// //             CHECK_NOTHROW(chart1.add_sub(Father.name, Daughter.name));
// //             CHECK_NOTHROW(chart1.add_sub(Uncle.name, Cousin.name));

// //     // test level order
// //     vector<string> lvl_order;
// //     for (auto it = chart1.begin_level_order(); it != chart1.end_level_order(); ++it) {
// //         lvl_order.push_back(*it);
// //     }
// //             CHECK_EQ(lvl_order.at(0), Great_GrandFather.name);
// //             CHECK_EQ(lvl_order.at(1), Grandfather.name);
// //             CHECK_EQ(lvl_order.at(2), Father.name);
// //             CHECK_EQ(lvl_order.at(3), Uncle.name);
// //             CHECK_EQ(lvl_order.at(4), Aunt.name);
// //             CHECK_EQ(lvl_order.at(5), Son.name);
// //             CHECK_EQ(lvl_order.at(6), Daughter.name);
// //             CHECK_EQ(lvl_order.at(7), Cousin.name);


// //     lvl_order.clear();
// //     //add another field and check that it works
// //     Person Cousin2("Cousin2", 14);
// //             CHECK_NOTHROW(chart1.add_sub(Aunt.name, Cousin2.name));

// //     //check default iterator
// //     for (auto person: chart1) {
// //         lvl_order.push_back(person);
// //     }
// //             CHECK_EQ(lvl_order.at(0), Great_GrandFather.name);
// //             CHECK_EQ(lvl_order.at(1), Grandfather.name);
// //             CHECK_EQ(lvl_order.at(2), Father.name);
// //             CHECK_EQ(lvl_order.at(3), Uncle.name);
// //             CHECK_EQ(lvl_order.at(4), Aunt.name);
// //             CHECK_EQ(lvl_order.at(5), Son.name);
// //             CHECK_EQ(lvl_order.at(6), Daughter.name);
// //             CHECK_EQ(lvl_order.at(7), Cousin.name);
// //             CHECK_EQ(lvl_order.at(8), Cousin2.name);


// //     //add another field and check that it works
// //     Person GreatUncle("GreatUncle", 62);
// //             CHECK_NOTHROW(chart1.add_sub(Great_GrandFather.name, GreatUncle.name));

// //     // test reverse level order
// //     vector<string> rv_lvl_order;
// //     for (auto it = chart1.begin_reverse_order(); it != chart1.reverse_order(); ++it) {
// //         rv_lvl_order.push_back(*it);
// //     }
// //             CHECK_EQ(rv_lvl_order.at(0), Son.name);
// //             CHECK_EQ(rv_lvl_order.at(1), Daughter.name);
// //             CHECK_EQ(rv_lvl_order.at(2), Cousin.name);
// //             CHECK_EQ(rv_lvl_order.at(3), Cousin2.name);
// //             CHECK_EQ(rv_lvl_order.at(4), Father.name);
// //             CHECK_EQ(rv_lvl_order.at(5), Uncle.name);
// //             CHECK_EQ(rv_lvl_order.at(6), Aunt.name);
// //             CHECK_EQ(rv_lvl_order.at(7), Grandfather.name);
// //             CHECK_EQ(rv_lvl_order.at(8), GreatUncle.name);
// //             CHECK_EQ(rv_lvl_order.at(9), Great_GrandFather.name);

// //     // Change root check that still works
// //     Person GreatGrandma("GreatGrandma", 84);
// //             CHECK_NOTHROW(chart1.add_root(GreatGrandma.name));

// //     //test preorder
// //     vector<string> pre_order;
// //     for (auto it = chart1.begin_preorder(); it != chart1.end_preorder(); ++it) {
// //         pre_order.push_back(*it);
// //     }
// //             CHECK_EQ(pre_order.at(0), GreatGrandma.name);
// //             CHECK_EQ(pre_order.at(1), Grandfather.name);
// //             CHECK_EQ(pre_order.at(2), Father.name);
// //             CHECK_EQ(pre_order.at(3), Son.name);
// //             CHECK_EQ(pre_order.at(4), Daughter.name);
// //             CHECK_EQ(pre_order.at(5), Uncle.name);
// //             CHECK_EQ(pre_order.at(6), Cousin.name);
// //             CHECK_EQ(pre_order.at(7), Aunt.name);
// //             CHECK_EQ(pre_order.at(8), Cousin2.name);
// //             CHECK_EQ(pre_order.at(9), GreatUncle.name);

// //     //print tree for  convenience
// //     cout << chart1 << endl;
// //     //test arrow operator
// //     vector<int> arrow_test;
// //     for (auto it = chart1.begin_preorder(); it != chart1.end_preorder(); ++it) {
// //         arrow_test.push_back(it->length());
// //     }
// //             CHECK_EQ(arrow_test.at(0), 12);
// //             CHECK_EQ(arrow_test.at(1), 11);
// //             CHECK_EQ(arrow_test.at(2), 6);
// //             CHECK_EQ(arrow_test.at(3), 3);
// //             CHECK_EQ(arrow_test.at(4), 8);
// //             CHECK_EQ(arrow_test.at(5), 5);
// //             CHECK_EQ(arrow_test.at(6), 6);
// //             CHECK_EQ(arrow_test.at(7), 4);
// //             CHECK_EQ(arrow_test.at(8), 7);
// //             CHECK_EQ(arrow_test.at(9), 10);
// // }
// // TEST_CASE ("Case 2 Football Team")
// // {
// //     //checking string
// //     OrgChart chart2;
// //             CHECK_NOTHROW(chart2.add_root("Owner"));
// //             CHECK_NOTHROW(chart2.add_root("New_Owner"));
// //             CHECK_THROWS(chart2.add_sub("Owner" , "General Manager"));//Owner was replaced
// //             CHECK_THROWS(chart2.add_sub("Lebron James" , "General_Manager"));//no such value
// //             CHECK_NOTHROW(chart2.add_sub("New_Owner" , "General_Manager"));
// //             CHECK_NOTHROW(chart2.add_sub("New_Owner" , "Share_Holders"));
// //             CHECK_NOTHROW(chart2.add_sub("New_Owner" , "Head_of_operations"));
// //             CHECK_NOTHROW(chart2.add_sub("General_Manager" , "Head_Coach"));
// //             CHECK_NOTHROW(chart2.add_sub("General_Manager" , "Assistant_Coach"));
// //             CHECK_NOTHROW(chart2.add_sub("Head_of_operations" , "Team_Doctor"));
// //             CHECK_NOTHROW(chart2.add_sub("Head_of_operations" , "Head_Scout"));
// //             CHECK_NOTHROW(chart2.add_sub("Share_Holders" , "Sub_Share_Holder1"));
// //             CHECK_NOTHROW(chart2.add_sub("Share_Holders" , "Sub_Share_Holder2"));
// //             CHECK_THROWS(chart2.add_sub("head_of_operations" , "Cheerleader"));//Head not head
// //             CHECK_NOTHROW(chart2.add_sub("Head_Coach" , "Captain"));
// //             CHECK_NOTHROW(chart2.add_sub("Team_Doctor" , "Team_Physiotherapist"));
// //             // test level order
// //             vector<string> lvl_order;
// //             for (auto it = chart2.begin_level_order(); it != chart2.end_level_order(); ++it)
// //             {
// //                lvl_order.push_back(*it);
// //             }
// //             CHECK_EQ(lvl_order.at(0),"New_Owner");
// //             CHECK_EQ(lvl_order.at(1),"General_Manager");
// //             CHECK_EQ(lvl_order.at(2),"Share_Holders");
// //             CHECK_EQ(lvl_order.at(3),"Head_of_operations");
// //             CHECK_EQ(lvl_order.at(4),"Head_Coach");
// //             CHECK_EQ(lvl_order.at(5),"Assistant_Coach");
// //             CHECK_EQ(lvl_order.at(6),"Sub_Share_Holder1");
// //             CHECK_EQ(lvl_order.at(7),"Sub_Share_Holder2");
// //             CHECK_EQ(lvl_order.at(8),"Team_Doctor");
// //             CHECK_EQ(lvl_order.at(9),"Head_Scout");
// //             CHECK_EQ(lvl_order.at(10),"Captain");
// //             CHECK_EQ(lvl_order.at(11),"Team_Physiotherapist");
// //             lvl_order.clear();

// //             //add another field and check that it works
// //             CHECK_NOTHROW(chart2.add_sub("Assistant_Coach" , "Water_Boy"));
// //              cout << chart2 << endl;
// //             //check default iterator
// //             for (auto name:chart2)
// //             {
// //                 lvl_order.push_back(name);
// //             }
// //             CHECK_EQ(lvl_order.at(0),"New_Owner");
// //             CHECK_EQ(lvl_order.at(1),"General_Manager");
// //             CHECK_EQ(lvl_order.at(2),"Share_Holders");
// //             CHECK_EQ(lvl_order.at(3),"Head_of_operations");
// //             CHECK_EQ(lvl_order.at(4),"Head_Coach");
// //             CHECK_EQ(lvl_order.at(5),"Assistant_Coach");
// //             CHECK_EQ(lvl_order.at(6),"Sub_Share_Holder1");
// //             CHECK_EQ(lvl_order.at(7),"Sub_Share_Holder2");
// //             CHECK_EQ(lvl_order.at(8),"Team_Doctor");
// //             CHECK_EQ(lvl_order.at(9),"Head_Scout");
// //             CHECK_EQ(lvl_order.at(10),"Captain");
// //             CHECK_EQ(lvl_order.at(11),"Water_Boy");
// //             CHECK_EQ(lvl_order.at(12),"Team_Physiotherapist");

// //             // test reverse level order
// //             vector<string> rv_lvl_order;
// //             for (auto it = chart2.begin_reverse_order(); it != chart2.reverse_order(); ++it)
// //             {
// //                 rv_lvl_order.push_back(*it);
// //             }
// //             CHECK_EQ(rv_lvl_order.at(0),"Captain");
// //             CHECK_EQ(rv_lvl_order.at(1),"Water_Boy");
// //             CHECK_EQ(rv_lvl_order.at(2),"Team_Physiotherapist");
// //             CHECK_EQ(rv_lvl_order.at(3),"Head_Coach");
// //             CHECK_EQ(rv_lvl_order.at(4),"Assistant_Coach");
// //             CHECK_EQ(rv_lvl_order.at(5),"Sub_Share_Holder1");
// //             CHECK_EQ(rv_lvl_order.at(6),"Sub_Share_Holder2");
// //             CHECK_EQ(rv_lvl_order.at(7),"Team_Doctor");
// //             CHECK_EQ(rv_lvl_order.at(8),"Head_Scout");
// //             CHECK_EQ(rv_lvl_order.at(9),"General_Manager");
// //             CHECK_EQ(rv_lvl_order.at(10),"Share_Holders");
// //             CHECK_EQ(rv_lvl_order.at(11),"Head_of_operations");
// //             CHECK_EQ(rv_lvl_order.at(12),"New_Owner");

// //             // Change root check that still works
// //             CHECK_NOTHROW(chart2.add_root("Stan_Kronke"));

// //             //test preorder
// //             vector<string> pre_order;
// //             for (auto it = chart2.begin_preorder(); it != chart2.end_preorder(); ++it)
// //             {
// //                 pre_order.push_back(*it);
// //             }
// //             CHECK_EQ(pre_order.at(0),"Stan_Kronke");
// //             CHECK_EQ(pre_order.at(1),"General_Manager");
// //             CHECK_EQ(pre_order.at(2),"Head_Coach");
// //             CHECK_EQ(pre_order.at(3),"Captain");
// //             CHECK_EQ(pre_order.at(4),"Assistant_Coach");
// //             CHECK_EQ(pre_order.at(5),"Water_Boy");
// //             CHECK_EQ(pre_order.at(6),"Share_Holders");
// //             CHECK_EQ(pre_order.at(7),"Sub_Share_Holder1");
// //             CHECK_EQ(pre_order.at(8),"Sub_Share_Holder2");
// //             CHECK_EQ(pre_order.at(9),"Head_of_operations");
// //             CHECK_EQ(pre_order.at(10),"Team_Doctor");
// //             CHECK_EQ(pre_order.at(11),"Team_Physiotherapist");
// //             CHECK_EQ(pre_order.at(12),"Head_Scout");

// //             //test arrow operator
// //             vector<char> arrow_test;
// //             for (auto it = chart2.begin_preorder(); it != chart2.end_preorder(); ++it)
// //             {
// //                 arrow_test.push_back(it->at(0));
// //             }
// //             CHECK_EQ(arrow_test.at(0),'S');
// //             CHECK_EQ(arrow_test.at(1),'G');
// //             CHECK_EQ(arrow_test.at(2),'H');
// //             CHECK_EQ(arrow_test.at(3),'C');
// //             CHECK_EQ(arrow_test.at(4),'A');
// //             CHECK_EQ(arrow_test.at(5),'W');
// //             CHECK_EQ(arrow_test.at(6),'S');
// //             CHECK_EQ(arrow_test.at(7),'S');
// //             CHECK_EQ(arrow_test.at(8),'S');
// //             CHECK_EQ(arrow_test.at(9),'H');
// //             CHECK_EQ(arrow_test.at(10),'T');
// //             CHECK_EQ(arrow_test.at(11),'T');
// //             CHECK_EQ(arrow_test.at(12),'H');
// // }








// // // ====================================================== ranana ==============================================

// // #include "doctest.h"
// // #include "OrgChart.hpp"
// // using namespace ariel;

// // /*Renana Rimon*/

// // TEST_CASE("BUILD_ORG"){
// //     OrgChart org;
// //     OrgChart org_empty;
// //     OrgChart org_double_names;
// //     /* create normal tree */
// //     CHECK_THROWS_MESSAGE(org.add_sub("tal", "renana"), "can't add sub before root");
// //     CHECK_NOTHROW(org.add_root("dana"));
// //     CHECK_NOTHROW(org.add_root("shir"));
// //     CHECK_NOTHROW(org.add_sub("shir", "tal"));
// //     CHECK_THROWS_MESSAGE(org.add_sub("adi", "sapir"), "employer doesn't exist");
// //     CHECK_NOTHROW(org.add_sub("shir", "sapir"));
// //     CHECK_NOTHROW(org.add_sub("sapir", "dan"));
// //     CHECK_NOTHROW(org.add_sub("dan", "ziv"));
// //     CHECK_NOTHROW(org.add_sub("tal", "avi"));
// //     CHECK_NOTHROW(org.add_sub("tal", "yossi"));
// //     CHECK_NOTHROW(org.add_sub("shir", "ido"));
// //     CHECK_NOTHROW(org.add_sub("ziv", "shaked"));
// //     CHECK_NOTHROW(org.add_sub("ziv", "ofer"));


// //     /* create tree with 1 name*/
// //     CHECK_NOTHROW(org_double_names.add_root("adi"));
// //     for (size_t i = 0; i < 11; i++)
// //     {
// //         CHECK_NOTHROW(org_double_names.add_sub("adi", "adi"));
// //     }


// //     /**************************************************************/
// //     SUBCASE("level_order"){
// //         /*check level order with normal tree*/
// //         std::vector<std::string> v = {"shir", "tal", "sapir", "ido", "avi", "yossi", "dan", "ziv", "shaked", "ofer"};
// //         size_t i = 0;
// //         for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){
// //             CHECK_EQ(*it, v.at(i++));
// //         }
    
    

// //         /*check level order with empty tree*/
// //         // CHECK_THROWS_MESSAGE(org_empty.begin_level_order(), "chart is empty!");
// //         CHECK_THROWS_MESSAGE(org_empty.end_level_order(), "chart is empty!");
        

// //         /*check level order with 1 name tree*/
// //         for(auto it = org_double_names.begin_level_order(); it != org_double_names.end_level_order(); ++it){
// //             CHECK(*it == "adi");
// //         }
    
// //         /* check iter size*/
// //         std::vector<int> nums = {4, 3, 5, 3, 3, 5, 3, 3, 6, 4};
// //         int j = 0;
// //         for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){
// //             CHECK_EQ(it->size(), nums.at((size_t)j));
// //             j++;
// //         }

// //     }

// //     SUBCASE("reverse_level_order"){
// //         /*check reverse level order with normal tree*/
// //         std::vector<std::string> v = {"shaked", "ofer", "ziv", "avi", "yossi", "dan", "tal", "sapir", "ido", "shir"};
// //         size_t i = 0;
// //         for(auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
// //             cout << *it << '\n';
// //             fflush(stdout);
// //             CHECK_EQ(*it, v.at(i++));
// //         }
    
    

// //         /*check reverse level order with empty tree*/
// //         CHECK_THROWS_MESSAGE(org_empty.begin_reverse_order(), "chart is empty!");
// //         CHECK_THROWS_MESSAGE(org_empty.reverse_order(), "chart is empty!");

// //         /*check reverse level order with 1 name tree*/
// //         for(auto it = org_double_names.begin_reverse_order(); it != org_double_names.reverse_order(); ++it){
// //             CHECK(*it == "adi");
// //         }

// //         /* check iter size*/
// //         std::vector<size_t> nums = {6, 4, 3, 3, 5, 3, 3, 5, 3, 4};
// //         int j = 0;
// //         for(auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
// //             CHECK_EQ(it->size(), nums.at((size_t)j));
// //             j++;
// //         }

// //     }

// //     SUBCASE("PreOrder"){
// //         /*check PreOrder with normal tree*/
// //         std::vector<std::string> v = {"shir", "tal", "avi", "yossi", "sapir", "dan", "ziv", "shaked", "ofer", "ido"};
// //         size_t i = 0;
// //         for(auto it = org.begin_preorder(); it != org.end_preorder(); ++it){
// //             CHECK_EQ(*it, v.at(i++));
// //         }

// //         /*check PreOrder with empty tree*/
// //         CHECK_THROWS_MESSAGE(org_empty.begin_preorder(), "chart is empty!");
// //         CHECK_THROWS_MESSAGE(org_empty.end_preorder(), "chart is empty!");

// //         /*check PreOrder with 1 name tree*/
// //         for(auto it = org_double_names.begin_preorder(); it != org_double_names.end_preorder(); ++it){
// //             CHECK(*it == "adi");
// //         }
// //         /* check iter size*/
// //         std::vector<size_t> nums = {4, 3, 3, 5, 5, 3, 3, 6, 4, 3};
// //         int j = 0;
// //         for(auto it = org.begin_preorder(); it != org.end_preorder(); ++it){
// //             CHECK_EQ(it->size(), nums.at((size_t)j));
// //             j++;
// //         }
// //     }

// //     SUBCASE("special"){
// //         OrgChart org_special;
// //         CHECK_NOTHROW(org_special.add_root("boss"));
// //         CHECK_NOTHROW(org_special.add_root("boss1"));
// //         CHECK_NOTHROW(org_special.add_root("boss2"));
// //         CHECK_NOTHROW(org_special.add_root("boss3"));
// //         CHECK_NOTHROW(org_special.add_root("boss4"));
// //         CHECK_NOTHROW(org_special.add_root("boss5"));
// //         CHECK_NOTHROW(org_special.add_root("boss6"));

// //         /*check that org size is 1, and root is the last*/
// //         int i =0; 
// //         for(auto it = org_special.begin_preorder(); it != org_special.end_preorder(); ++it){
// //             CHECK(*it == "boss6");
// //             CHECK(i==0);
// //             i++;
// //         }


// //     }



// // }