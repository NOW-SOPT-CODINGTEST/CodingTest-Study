#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;

int main() {
    FASTIO
    int N;
    cin>> N;
    vector<int> v;
    vector<int> dp(N, 0);
    for(int i=0; i<N; i++){
        int amount;
        cin>> amount;
        v.push_back(amount);
    }
    
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(dp[1], max(v[1]+ v[2], v[0]+ v[2]));
//    dp[3] = max(dp[2], dp[1]+v[3], dp[0]+v[2]+v[3]);
//    dp[n] = max[dp[n-1], dp[n-2]+v[n], dp[n-3]+ v[n-1]+v[n]]
    
    for(int i = 3; i< N; i++){
        dp[i] = max(dp[i-1], max(dp[i-2]+v[i], dp[i-3]+ v[i-1]+v[i]));
    }
    cout << dp[N-1];
}
