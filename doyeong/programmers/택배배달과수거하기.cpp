// 내 코드
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    
    priority_queue<pair<int, int>> deli_pq;
    priority_queue<pair<int, int>> pick_pq;
    
    for(int i=0; i<n; i++){
        if(deliveries[i] != 0){
            deli_pq.push({i+1, deliveries[i]});
        }
        if(pickups[i] != 0){
            pick_pq.push({i+1, pickups[i]});
        }
        // cout << i+1 << " " << deliveries[i] << " " << pickups[i] << endl;
    }

    int total_dir = 0;
    
    while(!deli_pq.empty() && !pick_pq.empty()){
        int now_cap = cap;
        int dir = 0;
        
        int max_deli = 0;
        int max_pick = 0;
        if(!deli_pq.empty()) max_deli = deli_pq.top().first;
        if(!pick_pq.empty()) max_pick = pick_pq.top().first;
            
        int max_dir = max(max_deli, max_pick);

        // cout << "max_dir: " << max_dir << endl;

        if(!deli_pq.empty()){
            for(int i=deli_pq.top().first; i>0; i--){
                // cout << "deli: " << deli_pq.top().first << " now_cap: " << now_cap  << " " << deli_pq.top().second << endl;
                if(now_cap - deli_pq.top().second >=0){
                    now_cap -= deli_pq.top().second;
                    deli_pq.pop();

                    if(deli_pq.empty()) break;
                }
                else {
                    now_cap = deli_pq.top().second - now_cap;
                    deli_pq.push({deli_pq.top().first, now_cap});
                    deli_pq.pop();
                    break;
                }
            }
        }

        now_cap = cap;

        if(!pick_pq.empty()){
            for(int i=pick_pq.top().first; i>0; i--){
                // cout << "pick: " << pick_pq.top().first << " now_cap: " << now_cap  << " " << pick_pq.top().second << endl;
                if(pick_pq.top().second <= now_cap){
                    now_cap -= pick_pq.top().second;
                    pick_pq.pop();

                    if(pick_pq.empty()) break;
                }
                else {
                    now_cap = deli_pq.top().second - now_cap;
                    pick_pq.push({pick_pq.top().first, now_cap});
                    pick_pq.pop();
                    break;
                }
            }
        }

        total_dir += max_dir * 2;
    }
    
    answer = total_dir;
    
    return answer;
}

// 답안 코드
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll solution(int cap, int n, vector<int> d, vector<int> p) {
    ll ans = 0;
    ll a = 0;
    ll b = 0;
    for(int i=n-1; i>=0; i--) {
        a -= d[i];
        b -= p[i];
        int cnt = 0;
        while(a < 0 || b < 0) {
            a += cap;
            b += cap;
            cnt++;
        }
        ans += (i + 1) * 2 * cnt;
    }
    return ans;
}