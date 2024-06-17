#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, S;
    cin >> N >> S;

    vector<int> v;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    int start = 0;
    int end = 0;
    int sum = v[0];
    int min_len = 987654321;

    while(end < N){
        if(sum < S) {
            end++;
            sum += v[end];
        }
        else {
            min_len = min(min_len, end-start+1);
            sum -= v[start];
            start++;
        }
    }

    if(min_len == 987654321) cout << 0;
    else cout << min_len;

    return 0;
}