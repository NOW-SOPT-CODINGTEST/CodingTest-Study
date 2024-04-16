// 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱

#include<iostream>

#define endl "\n"
using namespace std;

int N, M;

long long exp(int len, long long number){
    if(len == M){
        return number;
    } else {
        return exp(len+1, number * N);
    }
}

int main(int argc, char** argv)
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int test_case;
	int T=10;
	
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num;
        cin >> num;

        cin >> N >> M;

        

        cout << "#" << num << " " << exp(1, N) << endl;
	}
	return 0;
}