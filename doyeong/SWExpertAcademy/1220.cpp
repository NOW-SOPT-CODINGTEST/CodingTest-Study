// 1220. [S/W 문제해결 기본] 5일차 - Magnetic
#include<iostream>
#include<cstring>

#define endl "\n"
using namespace std;

int board[100+5][100+5];
int result = 0;

void check(int col){

    int prior = 0;

    for(int i=0; i<100; i++){
        if(board[i][col] == 1) {
            prior = 1;
        }
        if(board[i][col] == 2){
            if(prior == 1){
                result++;
                prior = 0;
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int len;
        cin >> len;

        memset(board, 0, sizeof(board));

        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> board[i][j];
            }
        }

        result = 0;

        for(int i=0; i<100; i++){
            check(i);
        }

        cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}