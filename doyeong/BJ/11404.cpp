#include <iostream>

using namespace std;

const int INF = 987654321;

int n;
int dist[100+5][100+5];

void func() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            if(i == j) dist[i][j]=0;
			else dist[i][j] = INF;
		}
	}

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    func();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INF){
                cout << 0 << " ";
            } 
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}