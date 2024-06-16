#include <iostream>
// #include <string>

using namespace std;

int main(){

    string s, e;
    getline(cin, s);
    getline(cin, e);
    if(s == e){
        cout << "24:00:00" << endl;
        return 0;
    }

    int h1 = stoi(s.substr(0, 2));
    int m1 = stoi(s.substr(3, 2));
    int s1 = stoi(s.substr(6, 2));

    int h2 = stoi(e.substr(0, 2));
    int m2 = stoi(e.substr(3, 2));
    int s2 = stoi(e.substr(6, 2));

    if(s2 - s1 < 0){
        s2 += 60;
        m2 -= 1;
    }

    if(m2 - m1 < 0){
        m2 += 60;
        h2 -= 1;
    }

    if(h2 - h1 < 0){
        h2 += 24;
    }

    int res_h = h2 - h1;
    int res_m = m2 - m1;
    int res_s = s2 - s1;

    cout << (res_h < 10 ? "0" : "") << res_h << ":";
    cout << (res_m < 10 ? "0" : "") << res_m << ":";
    cout << (res_s < 10 ? "0" : "") << res_s << endl;

    return 0;
}