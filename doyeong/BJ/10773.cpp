#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
#include<sstream>
#include<cmath>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    stack<int> s;

    int K;
    cin >> K;

    while(K--){
        int num;
        cin >> num;

        if(num == 0){
            s.pop();
            continue;
        }

        s.push(num);
    }

    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}