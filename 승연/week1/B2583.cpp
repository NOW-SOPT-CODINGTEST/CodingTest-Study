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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> v(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));

int bfs(int x, int y, int M, int N)
{
    int size = 1;
    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(x, y));
    visited[x][y] = true;

    while (!Q.empty())
    {
        int nx = Q.front().first;
        int ny = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = nx + dx[i];
            int newy = ny + dy[i];

            if (0 <= newy and newy < N and 0 <= newx and newx < M)
            {
                if (!visited[newx][newy] and v[newx][newy] == 0)
                {
                    Q.push({newx, newy});
                    visited[newx][newy] = true;
                    size++;
                }
            }
        }
    }
    return size;
}

int main()
{
    FASTIO

    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int lbx, lby, rtx, rty;
        cin >> lbx >> lby >> rtx >> rty;

        //        인풋 받아서 영역 맵에 1로 표시
        for (int k = lby; k < rty; k++)
        {
            for (int j = lbx; j < rtx; j++)
            {
                v[k][j] = 1;
            }
        }
    }

    int cnt = 0;
    vector<int> sizes;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[i][j] == 0 and !visited[i][j])
            {
                cnt++;
                sizes.push_back(bfs(i, j, M, N));
            }
        }
    }
    cout << cnt << '\n';
    sort(sizes.begin(), sizes.end());
    for (int size : sizes)
    {
        cout << size << ' ';
    }
}
