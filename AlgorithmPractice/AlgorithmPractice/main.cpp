//# 은 금으로 막혀있어 지나갈 수 없는 칸
//. 비어있는 칸은
//시작지점은 'S'로 표현
//탈출 출구는 'E'
//각 층 사이에는 빈줄이 있으며, 입력의 끝은 L,R,C가 모두 0으로 표현된다.
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define MAX 31

int L,R,C; //빌딩의 층수, 세로, 가로
char building[MAX][MAX][MAX]; //층수, 세로, 가로
bool visited[MAX][MAX][MAX]; //층수, 세로, 가로
int time_building[MAX][MAX][MAX];

int dh[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
int currentH;
int currentY;
int currentX;
int destH;
int destY;
int destX;

void bfs() {
    queue<pair<int, pair<int, int>>> q; //층수, y, x
    q.push(make_pair(currentH, make_pair(currentY, currentX)));
    
    while(!q.empty()) {
        int h = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        
        if(h == destH && y == destY && x == destX) {
            cout << "Escaped in " << time_building[h][y][x] << " minute(s).\n";
            return;
        }
        
        for(int k = 0; k < 6; k++) {
            int mh = h + dh[k];
            int my = y + dy[k];
            int mx = x + dx[k];
            
            if(mh >= 0 && mh < L && my >= 0 && my < R && mx >= 0 && mx < C) {
                if((!visited[mh][my][mx] && building[mh][my][mx] == '.') || building[mh][my][mx] == 'E') {
                    visited[mh][my][mx] = true;
                    q.push(make_pair(mh, make_pair(my, mx)));
                    time_building[mh][my][mx] = time_building[h][y][x] + 1;
                }
            }
        }
        
    }
    
    cout << "Trapped!\n";
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    while(true) {
        memset(building, 0, sizeof(building));
        memset(visited, false, sizeof(visited));
        memset(time_building, 0, sizeof(time_building));
        
        //cin >> L >> R >> C;
        scanf("%d %d %d", &L, &R, &C);
        if(L == 0 && R == 0 && C == 0)
            return 0;
        
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S') {
                        currentH = i;
                        currentY = j;
                        currentX = k;
                    }
                    if(building[i][j][k] == 'E') {
                        destH = i;
                        destY = j;
                        destX = k;
                    }
                }
            }
        }
        
        bfs();
    }
}
