#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"

using namespace std;

const int INF = 987654321;

int main(){

    FASTIO

    int N, K;
    cin >> N;
    cin >> K;

    // board[r][c] = 1 means apple is in (r, c)
    // snake is in (r, c) if board[r][c] = 2
    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i=0; i<K; i++){
        int r, c;
        cin >> r >> c;

        board[r-1][c-1] = 1;
    }
    board[0][0] = 2;

    int L;
    cin >> L;

    // 방향 변환 정보 저장
    queue<pair<int, char>> dir;
    
    for(int i=0; i<L; i++){
        int X;
        char C;
        cin >> X >> C;

        dir.push({X, C});
    }

    bool running = true;
    int time = 1;
    int now_dir = 0; // 0: right, 1: down, 2: left, 3: up
    pair<int, int> head = {0, 0};
    queue<pair<int, int>> body;
    body.push({0, 0});

    while(running) {

        if(now_dir == 0){
            head.second++;

            if(head.second > N-1 || board[head.first][head.second] == 2){
                running = false;
                break;
            } else if(board[head.first][head.second] == 1){
                body.push({head.first, head.second});
                board[head.first][head.second] = 2;
            } else if(board[head.first][head.second] == 0){
                body.push({head.first, head.second});
                board[body.front().first][body.front().second] = 0;
                board[head.first][head.second] = 2;
                body.pop();
            }
        } else if (now_dir == 1){
            head.first++;

            if(head.first > N-1 || board[head.first][head.second] == 2){
                running = false;
                break;
            } else if(board[head.first][head.second] == 1){
                body.push({head.first, head.second});
                board[head.first][head.second] = 2;
            } else if(board[head.first][head.second] == 0){
                body.push({head.first, head.second});
                board[body.front().first][body.front().second] = 0;
                board[head.first][head.second] = 2;
                body.pop();
            }
        } else if (now_dir == 2){
            head.second--;

            if(head.second < 0 || board[head.first][head.second] == 2){
                running = false;
                break;
            } else if(board[head.first][head.second] == 1){
                body.push({head.first, head.second});
                board[head.first][head.second] = 2;
            } else if(board[head.first][head.second] == 0){
                body.push({head.first, head.second});
                board[body.front().first][body.front().second] = 0;
                board[head.first][head.second] = 2;
                body.pop();
            }
        } else if (now_dir == 3){
            head.first--;

            if(head.first < 0 || board[head.first][head.second] == 2){
                running = false;
                break;
            } else if(board[head.first][head.second] == 1){
                body.push({head.first, head.second});
                board[head.first][head.second] = 2;
            } else if(board[head.first][head.second] == 0){
                body.push({head.first, head.second});
                board[body.front().first][body.front().second] = 0;
                board[head.first][head.second] = 2;
                body.pop();
            }
        }

        int now_time = dir.front().first;
        
        if(now_time == time){
            if(dir.front().second == 'D'){
                now_dir = (now_dir + 1) % 4;
            } else {
                now_dir = (now_dir + 3) % 4;
            }
            dir.pop();
        }

        time++;
    }

    cout << time;

    return 0;
}