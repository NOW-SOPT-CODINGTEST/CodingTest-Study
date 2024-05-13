#include <iostream>

using namespace std;

const int INF = 987654321;

int dist[501][501];
int N, M;

void func() {
	for (int k=1; k<=N; k++) {
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main () {

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;

        dist[a][b] = 1;
    }

    func();

    int answer = 0;
    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(dist[i][j] != INF || dist[j][i] != INF){
                cnt++;
            }
        }
        if(cnt == N){
            answer++;
        }
    }

    cout << answer;

    return 0;
}