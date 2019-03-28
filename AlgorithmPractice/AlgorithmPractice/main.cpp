#include <iostream>
#include <queue>
using namespace std;
#define MAX 11

int N, M;
char board[MAX][MAX];
int rx, ry, bx, by;
bool visited[MAX][MAX][MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {rx, ry}, {bx, by} });
    visited[rx][ry][bx][by] = true;
    int cnt = 0;
    
    while(!q.empty()) {
        int qSize = (int)q.size();
        
        for(int j = 0; j < qSize; j++) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second.first;
            int w = q.front().second.second;
            q.pop();
            
            if(board[x][y] == 'O' && board[x][y] != board[z][w]) {
                return cnt;
            }
            
            for(int i = 0; i < 4; i++) {
                int cx = x;
                int cy = y;
                int cz = z;
                int cw = w;
                
                while(board[cx + dx[i]][cy + dy[i]] != '#' && board[cx][cy] != 'O'){
                    cx = cx + dx[i];
                    cy = cy + dy[i];
                }
                
                while(board[cz + dx[i]][cw+dy[i]] != '#' && board[cz][cw] != 'O') {
                    cz = cz + dx[i];
                    cw = cw + dy[i];
                }
                
                if(cx == cz && cy == cw) {
                    if(board[cx][cy] == 'O')
                        continue;
                    
                    if(abs(cx-x) + abs(cy-y) < abs(cz-z) + abs(cw-w)) {
                        cz = cz - dx[i];
                        cw = cw - dy[i];
                    }
                    else {
                        cx = cx - dx[i];
                        cy = cy - dy[i];
                    }
                }
                
                if(visited[cx][cy][cz][cw])
                    continue;
                q.push({ {cx, cy}, {cz, cw} });
                visited[cx][cy][cz][cw] = true;
            }
        }
        
        if(cnt == 10)
            return -1;
        cnt++;
    }
    
    
    return -1;
}

int main() {
    cout << "start" << endl;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            else if(board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    
    cout << bfs() << endl;
    
    return 0;
}
