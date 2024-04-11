#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#define ll long long
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;

int main() {
    FASTIO
    string X, Y;
    string res;
    cin>> X>>Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    res = to_string(stoi(X)+ stoi(Y));
    reverse(res.begin(), res.end());
    cout<< stoi(res);
}
