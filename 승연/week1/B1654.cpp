#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll res = 0, N, K;
    vector<ll> vec;
    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        ll num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), less<>());

    ll start = 1, end = vec[K - 1], mid;

    while (start <= end)
    {
        ll cur = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < K; i++)
        {
            cur += vec[i] / mid;
        }

        if (cur >= N)
        {
            start = mid + 1;
            res = max(res, mid);
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}
