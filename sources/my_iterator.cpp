
// #include "my_iterator.hpp"

// namespace ariel
// {
//         T& my_iterator::operator*() const{
//             return root.front()->name;
//         }

//         T* my_iterator::operator->() const{
//             return &(this->front()->name);
//         }

//         my_iterator& my_iterator::operator++(){
//             root.erase(root.begin());
//             return *this;
//         }

//         const my_iterator my_iterator::operator++(int){
//             my_iterator ans = *this;
//             root.erase(root.begin());
//             return ans;
//         }

//         bool my_iterator::operator==(const my_iterator& element) const{
//             return root.size() > 0 && element.size() > 0 && root.front()->name == *element;
//         }

//         bool my_iterator::operator!=(const my_iterator& element) const{
//             return !((*this) == element);
//         }


// }