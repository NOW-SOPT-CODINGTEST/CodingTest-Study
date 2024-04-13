#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <cstring>
#include <queue>
#define ll long long
#define FASTIO                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);

using namespace std;

vector<vector<int>> v(100, vector<int>());
vector<int> visited(100, 0);

int bfs(int p1, int p2)
{
    queue<int> Q;
    Q.push(p1);
    visited[p1] = 1;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        if (x == p2)
        {
            return visited[x] - 1;
        }

        for (int i = 0; i < v[x].size(); i++)
        {
            int nx = v[x][i];
            if (visited[nx] == 0)
            {
                Q.push(nx);
                visited[nx] = visited[x] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    FASTIO

    int N, M;
    cin >> N;
    int p1, p2;
    cin >> p1 >> p2;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if (p1 == p2)
    {
        cout << 0;
        return 0;
    }

    cout << bfs(p1, p2);
}
