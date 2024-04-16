//BOJ_2623 음악프로그램 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[1003];
int indegree[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        int prev, cur;
        cin >> prev;
        for (int j = 1; j < K; j++) {
            cin >> cur;
            indegree[cur]++;
            adj[prev].push_back(cur);
            prev = cur;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for (int nxt: adj[cur]) {
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }

    if (ans.size() != N) {
        cout << 0 << '\n';
    } else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << '\n';
        }
    }
}