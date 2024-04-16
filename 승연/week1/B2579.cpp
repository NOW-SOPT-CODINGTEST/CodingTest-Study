#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);

using namespace std;

int main()
{
    FASTIO
    int N;
    cin >> N;
    vector<int> v;
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        int stair;
        cin >> stair;
        v.push_back(stair);
    }

    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(v[0] + v[2], v[1] + v[2]);
    dp[3] = max(dp[1] + v[3], dp[0] + v[2] + v[3]);

    for (int i = 3; i < N; i++)
    {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }

    cout << dp[N - 1];
}
