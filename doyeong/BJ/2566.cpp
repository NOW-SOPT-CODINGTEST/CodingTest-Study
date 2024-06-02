#include <iostream>

using namespace std;

int main(void){

    int max = 0;
    int x, y;

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            int num;
            cin >> num;

            if(num >= max){
                max = num;
                x = i;
                y = j;
            }
        }
    }

    cout << max << endl;
    cout << x << " " <<  y;

    return 0;
}