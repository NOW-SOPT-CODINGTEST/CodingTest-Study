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

vector<int> bfs(int x, vector<int> visited, int N, vector<vector<int>> v)
{
    queue<int> Q;
    Q.push(x);

    while (!Q.empty())
    {
        int nx = Q.front();
        Q.pop();

        for (int i = 0; i < v[nx].size(); i++)
        {
            int newx = v[nx][i];
            if (!visited[newx])
            {
                visited[newx] = 1;
                Q.push(newx);
            }
        }
    }
    return visited;
}

int main()
{
    FASTIO

    int N;
    cin >> N;
    vector<vector<int>> v(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp)
            {
                v[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> visited(N, 0);
        visited = bfs(i, visited, N, v);
        for (int j = 0; j < visited.size(); j++)
        {
            cout << visited[j] << " ";
        }
        cout << '\n';
    }
}
