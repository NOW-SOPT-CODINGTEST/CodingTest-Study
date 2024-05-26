#include <iostream>
#include <queue>

using namespace std;

int N;
int board[1005][1005];
int dp[1005][1005]; 

int main (void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int info;
            cin >> info;

            board[i][j] = info;
        }
    }

    if(board[1][1] == 0) dp[1][1] = 1;
    else dp[1][1] = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == 1 && j != 1) {
                if(board[i][j] == dp[i][j-1]%3){
                    dp[i][j] = dp[i][j-1] + 1;
                }
                else dp[i][j] = dp[i][j-1];
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    if(board[i][j] == dp[i-1][j]%3){
                        dp[i][j] = dp[i-1][j] + 1;
                    }
                    else dp[i][j] = dp[i-1][j];
                } else {
                    if(board[i][j] == dp[i][j-1]%3){
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                    else dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout << dp[N][N];

    return 0;
}