// 1215. [S/W 문제해결 기본] 3일차 - 회문1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int board[10][10];

int main(){

    for(int T=1; T<=10; T++){
        int len;
        cin >> len;

        int result = 0;
        memset(board, 0, sizeof(board));
        

        for(int i=0; i<8; i++){
            string s;
            cin >> s;

            for(int j=0; j<8; j++){
                board[i][j] = s[j];
            }
        }

        for(int k=0; k<8; k++){
            for(int i=0; i<=8-len; i++){
                string r1 = "";
                string r2 = "";

                string c1 = "";
                string c2 = "";
                
                for(int j=i; j<i+len; j++){
                    r1 += to_string(board[k][j]);
                    r2 = to_string(board[k][j]) + r2;

                    c1 += to_string(board[j][k]);
                    c2 = to_string(board[j][k]) + c2;
                }

                if(r1 == r2){
                    result++;
                }

                if(c1 == c2){
                    result++;
                }
            }
        }
        
        cout << "#"<< T << " " << result << endl;
    }
}