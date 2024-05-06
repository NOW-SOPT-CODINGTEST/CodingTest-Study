#include <iostream>

using namespace std;

const int INF = 987654321;
int dist[100 + 5][100 + 5];
int N;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main (){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

    int x; 
    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (x == 1) {
				dist[i][j] = x;
			}
		}
	}

    func();

    for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) {
				cout << 0 << " ";
			}
			else cout << 1 << " ";
		}
		cout << "\n";
	}

    return 0;
}