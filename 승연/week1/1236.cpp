#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#define ll long long

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    cin.ignore();
    vector<vector<char>> v(N);

    for (int i = 0; i < N; i++)
    {
        string tmp;
        getline(cin, tmp);
        for (char c : tmp)
        {
            v[i].push_back(c);
        }
    }

    int rowX = 0, colX = 0;
    bool isOk;

    for (int i = 0; i < N; i++)
    {
        isOk = false;
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == 'X')
            {
                isOk = true;
            }
        }
        if (!isOk)
        {
            rowX += 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        isOk = false;
        for (int j = 0; j < N; j++)
        {
            if (v[j][i] == 'X')
            {
                isOk = true;
            }
        }
        if (!isOk)
        {
            colX += 1;
        }
    }
    cout << max(rowX, colX);
}
