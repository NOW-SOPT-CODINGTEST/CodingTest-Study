#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[100000+5][5][5];
vector<int> num;

int calc(int start, int end){
    if(start == 0){
        return 2;
    } else if(start == end){
        return 1; 
    } else if(abs(start - end) == 2){
        return 4;
    } else return 3;
}

int func(int idx, int left, int right){
    if(idx == num.size()) return 0;

    if(dp[idx][left][right] != -1) return dp[idx][left][right];

    int minLeft = func(idx + 1, num[idx], right) + calc(left, num[idx]);
    int minRight = func(idx + 1, left, num[idx]) + calc(right, num[idx]);
    return dp[idx][left][right] = min(minLeft, minRight);
}

int main(void){

    string s;
    getline(cin, s);

    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])) {
            if(s[i] == '0') break;
            else {
                num.push_back(s[i]-'0');
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << func(0, 0, 0);

    return 0;
}