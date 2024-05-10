#include <iostream>

using namespace std;

int N;
int dist[51][51];
const int INF = 987654321;

void func(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=N; i++){
        int cnt = 0;

        for(int j=1; j<=N; j++){
            if(dist[i][j] <= 2){
                cnt++;
            }
        }

        answer = max(answer, cnt);
    }

    cout << answer-1;
}

int main(){
    
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j] = INF;
        }
    }

    for(int i=1; i<=N; i++){
        string s;
        cin >> s;

        for(int j=1; j<=N; j++){
            if(s[j-1] == 'Y') dist[i][j] = 1;
        }
    }

    func();

    return 0;
}