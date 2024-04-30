#include<iostream>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N, M, d;
int board[55][55];
int result = 0;


void bfs(int x, int y, int dir){
    if(board[x][y] == 0){
        board[x][y] = 2;
        result++;
    }

    // cout << "x: " << x << " y: " << y << " dir: " << dir << endl;

    int vacant = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(board[nx][ny] == 0){
            vacant++;
        }
    }

    if(vacant > 0){
        dir = (dir + 3) % 4;
        if(board[x+dx[dir]][y+dy[dir]] == 0){
            bfs(x+dx[dir], y+dy[dir], dir);
        }
        else{
            bfs(x, y, dir);
        }
    } else {
        dir = (dir + 2) % 4;
        if(board[x+dx[dir]][y+dy[dir]] != 1){
            bfs(x+dx[dir], y+dy[dir], (dir + 2) % 4);
        }
        else {
            return;
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> M;

    int r, c;
    cin >> r >> c >> d;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[j][i];
        }
    }

    bfs(c, r, d);

    cout << result;

    return 0;
}