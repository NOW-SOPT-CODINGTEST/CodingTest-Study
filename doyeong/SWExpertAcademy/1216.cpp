#include<iostream>
#include<cstring>
#define endl "\n"

using namespace std;

char board[100+5][100+5];

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int len;
        cin >> len;

        int result = 0;

        for(int i=0; i<100; i++){
            string s;
            cin >> s;

            for(int j=0; j<100; j++){
                board[i][j] = s[j];
            }
        }

        bool flag = false;

        
        for(int i=100; i>0; i--){
            if(flag) break;

            for(int j=0; j<=100-i; j++){
                if(flag) break;

                string r1 = "";
                string r2 = "";

                string c1 = "";
                string c2 = "";

                for(int k=j; k<j+i; k++){
                    r1 += board[j][k];
                    r2 = board[j][k] + r2;

                    c1 += board[k][j];
                    c2 = board[k][j] + c2;
                }

                if(r1 == r2 || c1 == c2){
                    result = i;

                    flag = true;
                    break;
                }
            }
        }

        cout << "#" << len << " " << result << endl;
	}
	return 0;
}