#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int, int>> n[1001];
vector<pair<int, int>> m;
bool check[1001];
vector<int> result;

void dfs(int now, int end, int sum) {
    if (now == end) {
        result.push_back(sum);
        return;
    }

    for (int i = 0; i < n[now].size(); i++) {
        int next = n[now][i].first;
        int ns = sum + n[now][i].second;

        if (check[next]) continue;

        check[next] = true;
        dfs(next, end, ns);
    }
}

void func() {
    for (int i = 0; i < M; i++) {
        memset(check, false, sizeof(check));

        int start = m[i].first;
        int end = m[i].second;

        check[start] = true;
        dfs(start, end, 0);
    }

    for (int i = 0; i < M; i++) {
        cout << result[i] << endl;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        n[a].push_back({ b,c });
        n[b].push_back({ a,c });
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        m.push_back({ a,b });
    }

    func();

    return 0;
}
