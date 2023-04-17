#include <iostream>
#include <vector>
using namespace std;
/*
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
*/ 
/*
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
  
    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        const_cast<student*>(this)->roll = 5;
    }
  
    int getRoll()  { return roll; }
};
*/
/*
int main(void)
{
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;
  
    s.fun();
  
    cout << "New roll number: " << s.getRoll() << endl;
  
    return 0;
}
*/
/*
int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}
*/
/*
int main(void)
{
    int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    fun(ptr1);
    cout << val;
    return 0;
}
*/
/*
int main(void)
{
    int a1 = 40;
    const int* b1 = &a1;
    char* c1 = (char *)(b1);
    *c1 = 'A';
    cout << *c1 << endl;
    return 0;
}
*/
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
  
    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }
  
    int getRoll()  { return roll; }
};
  
int main(void)
{
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;
  
    s.fun();
  
    cout << "New roll number: " << s.getRoll() << endl;
  
    return 0;
}