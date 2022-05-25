// // #pragma once
// // #include <string>
// // #include <string.h>
// // #include <iterator>
// // #include <vector>
// // #include <queue>
// // #include <iostream>

// #include "my_iterator.hpp"

// namespace ariel
// {
//     my_iterator<std::string>::my_iterator(){
//         this->root = NULL;
//     }

//     my_iterator<std::string>::my_iterator(employee* emps){
//         this->root = emps;
//     }

//     my_iterator<std::string>& my_iterator<std::string>::operator++(){
//         this->root = this->root->next_in_line;
//         return *this;
//     }

//     my_iterator<std::string> my_iterator<std::string>::operator++(int){
//         my_iterator ans = *this;
//         this->root = this->root->next_in_line;
//         return ans;
//     }

//     bool my_iterator<std::string>::operator==(const my_iterator& element) const{
//         return this->root == element.root;
//     }

//     bool my_iterator<std::string>::operator!=(const my_iterator& element) const{
//         return !(*this == element);
//     }

// }
