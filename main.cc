#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

/*template <typename T>
ostream& operator<<(ostream& os, T&& data) {
    os << data;
    return os;
}*/

/*template <typename T>
istream& operator>>(istream& is, T&& data) {
    is >> data;
    if(is.fail()) {
        is.setstate(ios::failbit);
    }
    return is;
}*/

//int main() {
    /* ostream */
    /*ostringstream oss{};
    ofstream ofs{"output.txt"};

    cout << 1;
    oss << 1;
    ofs << 1;*/

    /* istream */
    /*istringstream iss{};
    ifstream ifs{"input.txt"};
    int x;
    cin >> x;
    iss >> x;
    ifs >> x;*/

    /* Error Handle */
    /*while(ifs >> x) {
        cout << 1;
        cout << x;
    }*/

    /* Error Flags */
    /*ifs >> x;
    cout << ifs.fail(); */
//}

/* Converting from strings */
/*int main(int argc, char* argv[]) {
    int x;
    istringstream iss{argv[1]};
    if(!(iss >> x)) {
        iss.clear();
    }else{
        cout << x;
    }
    
    try {
        x = stoi(argv[1]);
    }
    catch(invalid_argument& e) {
        cout << "error" << endl;
    }
}*/

/*
int main() {
    stringstream ss{};
    ss << "123a bc hello";
    int n{};
    char c{};
    string str{};

    if(ss >> n >> n >> c) cout << n << " ";
    ss.clear();
    if(ss >> c >> c) cout << c << " ";
    ss.clear();
    if(ss >> str) cout << str << " ";
}
*/

/* Sequential Container */
int main() {
    /* array */
    /*std::array<int, 5> data{};
    for(unsigned i {}; i < data.size() ; i++) {
        cin >> data.at(i);
    }
    for(auto&& i: data) {
        cout << i << endl;
    }*/
    /* vector */
    /*std::vector<int> data{};
    int x{};
    while (cin >> x)
    {
        data.push_back(x);
    }
    for(auto&& i: data) {
        cout << i << endl;
    }*/
    /* list */
    std::list<int> data{};
    std::vector<int*> order{};
    int x;
    while (cin >> x)
    {
        data.push_back(x);
        order.push_back(&data.back());
    }
    data.sort();
    int i{0};
    for(auto&& val: data) {
        cout << "val= " << val << ", order=" << *order[i++] << endl;
    }
}