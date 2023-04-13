#include <iostream>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, T&& data) {
    os << data;
    return os;
}

int main() {
    operator << (cout,1) << 2;
    (cout << 2);
    cout;
}