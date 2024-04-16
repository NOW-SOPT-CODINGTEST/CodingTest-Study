//BOJ_1654 랜선 자르기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> line;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int K, N;
    cin >> K >> N;

    long long left = 1, right = 0;
    for (int i = 0; i < K; i++) {
        int ip; cin >> ip;
        line.push_back(ip);
        right = max(right, (long long)ip);
    }

    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;

        long long cur = 0;
        for (int i = 0; i < K; i++) {
            cur += (line[i] / mid);
        }

        if (cur >= N) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
    
}