#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include<cstring>
#include <queue>
#define ll long long
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;

int main() {
    FASTIO
    int N;
    cin >> N;
    vector<int> score(N, 0);
    vector<vector<int>> v(N, vector<int>(5, 0));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            int cls;
            cin >> cls;
            v[i][j] = cls;
        }
    }
    
    for(int i=0; i<N; i++){
//        i번 학생
        vector<bool> flag(N, false);
        for(int j =0; j<5; j++){
//            i번 학생의 5개 학년
            for(int k =0; k< N; k++){
//                전체 학생
                if(i==k){
                    continue;
                }
                if(v[i][j] == v[k][j] and !flag[k]){
                    flag[k] = true;
                    score[i]+=1;
                }
            }
        }
    }
    
    
    int maxScore = 0;
    for(int i : score){
        if (i>maxScore) maxScore = i;
    }
    for(int i=0; i<N; i++){
        if (score[i]==maxScore){
            cout << i+1;
            return 0;
        }
    }
    
}
