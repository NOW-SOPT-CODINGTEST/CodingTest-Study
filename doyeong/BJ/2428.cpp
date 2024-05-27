#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binary_search (int num) {
    int first = num + 1;
    int last = v.size() - 1;
    int mid;
    int re = num;

    while(first <= last){
        mid = (first + last) / 2;

        if(v[mid] * 9 <= v[num] * 10){
            first = mid + 1;
            re = mid;
        }
        else last = mid -1;
    }

    return re;
}

int main (){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;

        v.push_back(k);
    }

    sort(v.begin(), v.end());

    long long result = 0;

    for(int i=0; i<n; i++){
        result += binary_search(i)-i;
    }

    cout << result;

    return 0;
}