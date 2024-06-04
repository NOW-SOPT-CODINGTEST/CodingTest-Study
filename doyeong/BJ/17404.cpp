#include <iostream>

using namespace std;

int dp[1005][3+5][3+5];
int board[1005][3+5];

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> board[i][1] >> board[i][2] >> board[i][3];
    }
    
    dp[1][1][1] = board[1][1];
    dp[1][2][2] = board[1][2];
    dp[1][3][3] = board[1][3];

    dp[2][2][1] = board[1][1] + board[2][2];
    dp[2][1][1] = 987654321;
    dp[2][3][1] = board[1][1] + board[2][3];

    dp[2][1][2] = board[1][2] + board[2][1];
    dp[2][2][2] = 987654321;
    dp[2][3][2] = board[1][2] + board[2][3];

    dp[2][1][3] = board[1][3] + board[2][1];
    dp[2][3][3] = 987654321;
    dp[2][2][3] = board[1][3] + board[2][2];

    for(int i=3; i<N; i++){
        dp[i][1][1] = min(dp[i-1][2][1], dp[i-1][3][1]) + board[i][1];
        dp[i][2][1] = min(dp[i-1][1][1], dp[i-1][3][1]) + board[i][2];
        dp[i][3][1] = min(dp[i-1][1][1], dp[i-1][2][1]) + board[i][3];

        dp[i][1][2] = min(dp[i-1][2][2], dp[i-1][3][2]) + board[i][1];
        dp[i][2][2] = min(dp[i-1][1][2], dp[i-1][3][2]) + board[i][2];
        dp[i][3][2] = min(dp[i-1][1][2], dp[i-1][2][2]) + board[i][3];

        dp[i][1][3] = min(dp[i-1][2][3], dp[i-1][3][3]) + board[i][1];
        dp[i][2][3] = min(dp[i-1][1][3], dp[i-1][3][3]) + board[i][2];
        dp[i][3][3] = min(dp[i-1][1][3], dp[i-1][2][3]) + board[i][3];

        // cout << i << "번째: " <<  dp[i][1][1] << " " << dp[i][2][1] << " " << dp[i][3][1] << " " << dp[i][1][2] << " " << dp[i][2][2] << " " << dp[i][3][2] << " " << dp[i][1][3] << " " << dp[i][2][3] << " " << dp[i][3][3] << endl;
    }

    dp[N][2][1] = min(dp[N-1][3][1], dp[N-1][1][1]) + board[N][2];
    dp[N][3][1] = min(dp[N-1][2][1], dp[N-1][1][1]) + board[N][3];

    dp[N][1][2] = min(dp[N-1][3][2], dp[N-1][2][2]) + board[N][1];
    dp[N][3][2] = min(dp[N-1][1][2], dp[N-1][2][2]) + board[N][3];

    dp[N][1][3] = min(dp[N-1][2][3], dp[N-1][3][3]) + board[N][1];
    dp[N][2][3] = min(dp[N-1][1][3], dp[N-1][3][3]) + board[N][2];
    

    cout << min(dp[N][2][1], min(dp[N][3][1], min(dp[N][1][2], min(dp[N][3][2], min(dp[N][1][3], dp[N][2][3])))));

    return 0;
}