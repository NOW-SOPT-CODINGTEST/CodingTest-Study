#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

vector<pair<int, int>> schedule;
int N;
int result = 0;

void func(int day, int sum){

    if(day == N+1){
        result = max(result, sum);
        return;
    }

    func(day + 1, sum);
    if(day + schedule[day].first <= N+1){
        func(day + schedule[day].first, sum + schedule[day].second);
    }
}

int main(){

    FASTIO

    cin >> N;

    schedule.push_back({0, 0});

    for(int i=0; i<N; i++){
        int T, P;
        cin >> T >> P;
        
        schedule.push_back({T, P});
    }

    func(1 + 1, 0);
    if(1 + schedule[1].first <= N+1){
        func(1 + schedule[1].first, schedule[1].second);
    }

    cout << result;

    return 0;
}