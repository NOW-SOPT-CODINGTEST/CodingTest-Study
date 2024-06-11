#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    int max5 = N/5;
    int max3 = N/3;
    int now5 = 0;
    int now3 = 0;
    int sum = 0;

    for(int i=max5; i>=0; i--){
        for(int j=0; j<=max3; j++){
            int num = i*5 + j*3;

            if(num == N) {
                cout << i+j;
                return 0;
            }
            if(num > N) break;
        }
    }

    cout << -1;

    return 0;
}