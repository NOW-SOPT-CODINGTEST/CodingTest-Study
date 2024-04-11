#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#define ll long long
#define FASTIO                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);

using namespace std;

int main()
{
    FASTIO

    vector<int> v;
    for (int i = 1; i < 1001; i++)
    {
        for (int j = 0; j < i; j++)
        {
            v.push_back(i);
        }
    }
    int A, B;
    int res = 0;
    cin >> A >> B;
    for (int i = A - 1; i < B; i++)
    {
        res += v[i];
    }
    cout << res;
}
