#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main(void) {
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  vector<pair<int, int>> v;
  for (int i = 1; i <= N; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    v.push_back({tmp1, tmp2});
  }
  vector<bool> temp(v.size(), false);

  int ans = INF;
  for (int i = 1; i <= N; i++) {
    fill(temp.begin(), temp.end(), false);
    for (int j = 0; j < i; j++) { // 앞부터 i개의 true가 채워진다. 나머지 뒤는 false.
      temp[j] = true;
    }

    do {
      int sin = 0, zan = 0;
      for (int k = 0; k < v.size(); k++) {
        if (temp[k]) {
          if (sin == 0) {
            sin = v[k].first;
          } else
            sin *= v[k].first;
          zan += v[k].second;
        }
      }
      ans = min(ans, abs(sin - zan));
    } while (prev_permutation(temp.begin(), temp.end()));
  }
  cout << ans;
}