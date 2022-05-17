
// #include "my_iterator.hpp"

// namespace ariel
// {
//         my_iterator& my_iterator::operator++(){
//             this->root.erase(this->root.begin());
//             return *this;
//         }
//         my_iterator my_iterator::operator++(int){
//             my_iterator ans = *this;
//             (*this)++;
//             return ans;
//         }
//         bool my_iterator::operator==(const my_iterator& element) const{
//             if (!this->root.empty() && !element.root.empty())
//             {
//                 return this->root.at(0) == element.root.at(0);
//             }
//             return false;
//         }

//         bool my_iterator::operator!=(const my_iterator& element) const{
//             return !(*this == element);
//         }

// }