// N번째 큰 수

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int N;
    cin >> N;

    priority_queue<long long> pq;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num;
            
            pq.push(-num);

            if(pq.size() > N){
                pq.pop();
            }
        }
    }

    cout << -pq.top() << endl;

    return 0;
}