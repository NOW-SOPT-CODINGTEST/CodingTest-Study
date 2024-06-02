#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[300000+5];

int main(void){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> v;

    for(int i=1; i<=N; i++){
        int num; 
        cin >> num;
        
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i=0; i<N; i++){
        sum += v[i];
        board[i+1] = sum;
    }

    // for(int i=0; i<5; i++){
    //     cout << board[i+1] << " ";
    // }

    for(int i=0; i<Q; i++){
        int L, R;
        cin >> L >> R;

        cout << board[R] - board[L-1] << '\n';
    }

    return 0;
}