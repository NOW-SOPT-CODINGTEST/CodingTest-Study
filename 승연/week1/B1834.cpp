#include <iostream>
#define ll long long
#define FASTIO                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);

using namespace std;

int main()
{
    FASTIO

    ll N;
    cin >> N;
    ll res = 0;
    for (int i = 1; i < N; i++)
    {
        res += N * i + i;
    }

    cout << res;
}
