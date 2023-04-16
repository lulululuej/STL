#include <iostream>
#include <vector>

int main() {
   std::vector<int> v1{1, 2, 3};
   std::vector<int> v2{4, 5, 6, 7, 8, 9, 10};
   int x = *(v2.begin());
   std::cout << x << std::endl;
   std::move_backward(v1.begin(), v1.end(), v2.begin());
   for(auto i: v1) {
      std::cout << i << ",";
   }
   std::cout << "next" << std::endl;
   for(auto j: v2) {
      std::cout << j << ",";
   }
}