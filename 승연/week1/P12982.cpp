#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int cnt=0;
    sort(d.begin(), d.end());
    for(int i: d){
        if(budget>=i){
            budget-=i;
            cnt++;
        }
    }
    return cnt;
}