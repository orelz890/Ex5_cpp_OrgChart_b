// #pragma once
// #include <string>
// #include <string.h>
// #include <iterator>
// #include <vector>
// #include <queue>
// #include <iostream>

// #include "my_iterator.hpp"

// namespace ariel
// {
//     template<typename T> class my_iterator{

//         my_iterator::my_iterator(){
//             this->root = NULL;
//         }

//         my_iterator::my_iterator(employee* emps){
//             this->root = emps;
//         }

//         T& my_iterator::operator*() const{            
//             return this->root->name;
//         }

//         T* my_iterator::operator->() const{
//             return &(this->root->name);
//         }

//         my_iterator::my_iterator& operator++(){
//             this->root = this->root->next_in_line;
//             return *this;
//         }

//         const my_iterator my_iterator::operator++(int){
//             my_iterator ans = *this;
//             this->root = this->root->next_in_line;
//             return ans;
//         }

//         bool my_iterator::operator==(const my_iterator& element) const{
//             return this->root == element.root;
//         }

//         bool my_iterator::operator!=(const my_iterator& element) const{
//             return !(*this == element);
//         }

//     };
// }
