#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"
#define ll long long

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int K, N;
    cin >> K >> N;

    vector<ll> v;

    for(int i=0; i<K; i++){
        ll num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    ll left = 1;
    ll right = v[K-1];
    ll mid = (left + right) / 2;

    ll result = 0;

    while(left <= right){
        mid = (left + right) / 2;
        ll sum = 0;

        for(int i=0; i<K; i++){
            sum += v[i] / mid;
        }


        if(sum >= N){
            left = mid + 1;
            result = max(result, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << result;

    return 0;
}