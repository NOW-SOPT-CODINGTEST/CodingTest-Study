//BOJ_2458 순서 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int adj[501][501][2];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int a, b;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(i == j) continue;
            adj[i][j][0] = 1e9;
            adj[i][j][1] = 1e9;
        }
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b][0] = 1;
        adj[b][a][1] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                adj[r][c][0] = min(adj[r][i][0] + adj[i][c][0], adj[r][c][0]);
                adj[r][c][1] = min(adj[r][i][1] + adj[i][c][1], adj[r][c][1]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        bool find = true;
        for (int j = 1; j <= N; j++) {
            if (adj[i][j][0] == 1e9 && adj[i][j][1] == 1e9) {
                find = false;
                break;
            }
        }
        if (find) answer++;
    }
    
    cout << answer;
}