#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, X;
    cin >> N >> X;

    vector<int> v;

    int max_sum = -1;
    int sum = 0;
    int cnt = 0;
    int last = 0;

    bool flag = false;
    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        v.push_back(num);
        sum += num;

        if (i==X || flag){
            if (max_sum == sum){
                cnt += 1;
            } else if (max_sum < sum){
                max_sum = sum;
                cnt = 1;
            }
            sum -= v[i-X];
            flag = true;
        }
    }

    if(max_sum == 0){
        cout << "SAD";
    } else {
        cout << max_sum << endl;
        cout << cnt;
    }

    return 0;
}