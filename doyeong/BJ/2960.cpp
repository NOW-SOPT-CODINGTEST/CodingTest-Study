#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

bool isPrime[1001];

int main(){

    FASTIO

    int N, K;
    cin >> N >> K;

    queue<int> q;

    memset(isPrime, true, sizeof(isPrime));

    for(int i=2; i<=N; i++){
        if(isPrime[i]) {
            q.push(i);
            
            if(q.size() == K){
                cout << q.back() << endl;
                return 0;
            }

            for(int j=2; i*j<=N; j++){
                if(!isPrime[i*j]) continue;
                isPrime[i*j] = false;
                q.push(i*j);

                if(q.size() == K){
                    cout << q.back() << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}