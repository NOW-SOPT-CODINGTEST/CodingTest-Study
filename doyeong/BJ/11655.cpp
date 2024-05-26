#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + 13) % 26 + 'a';
        }
    }

    cout << s << endl;
    return 0;
}
