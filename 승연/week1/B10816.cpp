#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, card;
    vector<int> v(500002);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> card;
        v[i] = card;
    }

    sort(v.begin(), v.begin() + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> card;
        cout << upper_bound(v.begin(), v.begin() + N, card) - lower_bound(v.begin(), v.begin() + N, card) << ' ';
    }
}
