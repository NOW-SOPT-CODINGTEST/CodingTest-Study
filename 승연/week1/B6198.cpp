#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll cnt = 0;
    ll N;
    cin >> N;
    stack<ll> buildings;

    for (int i = 0; i < N; i++)
    {
        ll h;
        cin >> h;
        while (!buildings.empty() && buildings.top() <= h)
        {
            buildings.pop();
            cnt += buildings.size();
        }
        buildings.push(h);
    }
    while (!buildings.empty())
    {
        buildings.pop();
        cnt += buildings.size();
    }

    cout << cnt;
}
