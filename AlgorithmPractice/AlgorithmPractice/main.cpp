#include <iostream>
#include <queue>
using namespace std;
#define MAX 17

struct pipe {
    int y;
    int x;
    int dir;
};
//0=세로, 1=가로, 2=대각선
int dy[3] = {1, 0, 1};
int dx[3] = {0, 1, 1};
int board[MAX][MAX];
int N;
queue<pipe> q;
int ans = 0;

bool coverageCheck(int y, int x) {
    if(y >= 0 && y < N && x >= 0 && x < N && board[y][x] != 1)
        return true;
    return false;
}

void simulation() {
    q.push({0, 1, 1});
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int curDir = q.front().dir;
        q.pop();
        
        if(y == N-1 && x == N-1) {
            ans++;
            continue;
        }
        
        for(int i = 0; i < 3; i++) {
            //0=세로, 1=가로, 2=대각선
            int my = y + dy[i];
            int mx = x + dx[i];
            
            if(coverageCheck(my, mx) == false)
                continue;
            
            //현재상태가 가로로 있는 경우
            if(curDir == 1) {
                //세로로는 못움직임
                if(i == 0)
                    continue;
                if(i == 1) {
                    q.push({my, mx, 1});
                }
                if(i == 2) {
                    if(coverageCheck(y+1, x) == true && coverageCheck(y+1, x+1) == true && coverageCheck(y, x+1) == true) {
                        q.push({my, mx, 2});
                    }
                }
            }
            
            //현재상태가 세로로 있는 경우
            if(curDir == 0) {
                if(i == 0) {
                    q.push({my, mx, 0});
                }
                
                //가로로는 못움직임
                if(i == 1)
                    continue;
                
                if(i == 2) {
                    if(coverageCheck(y+1, x) == true && coverageCheck(y+1, x+1) == true && coverageCheck(y, x+1) == true) {
                        q.push({my, mx, 2});
                    }
                }
            }
            
            //현재상태가 대각선으로 있는 경우
            if(curDir == 2) {
                if(i == 0)
                    q.push({my, mx, 0});
                if(i == 1)
                    q.push({my, mx, 1});
                if(i == 2) {
                    if(coverageCheck(y+1, x) == true && coverageCheck(y+1, x+1) == true && coverageCheck(y, x+1) == true) {
                        q.push({my, mx, 2});
                    }
                }
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin >> N;
    //빈칸은 0, 벽은 1
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    simulation();
    cout << ans << endl;
    return 0;
}
