#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
#include<cmath>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int N;
vector<int> A;
vector<int> B;

int binary_search(int number){
    int left = 0;
    int right = N - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(A[mid] == number){
            return 1;
        }else if(A[mid] < number){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return 0;
}

int main(){

    FASTIO

    cin >> N;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        A.push_back(num);
    }

    sort(A.begin(), A.end());
    
    int M;
    cin >> M;

    vector<int> B(M);
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        cout << binary_search(num) << endl;
    }    

    return 0;
}