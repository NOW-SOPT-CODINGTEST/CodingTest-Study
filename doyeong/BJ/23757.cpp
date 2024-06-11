#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<int> v;
    priority_queue<int> pq;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    for(int i=0; i<M; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i=0; i<v.size(); i++){
        int now = pq.top();
        pq.pop();

        if(now < v[i]) {
            cout << 0;
            return 0;
        }
        else {
            pq.push(now - v[i]);
        }
    }

    cout << 1;
    return 0;
}