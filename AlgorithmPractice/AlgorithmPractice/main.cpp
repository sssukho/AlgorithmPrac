#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 1001

struct pos{
    int y;
    int x;
    int wallCnt;
    int wayCnt;
};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int map[MAX][MAX];
bool visited[MAX][MAX][11]; //몇개 부쉈는지

int N, M, K;
queue<pos> q;

int main() {
    cout << "start\n";
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &map[i][j]);
    
    q.push({0, 0, 0, 1});
    visited[0][0][0] = true;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int wallCnt = q.front().wallCnt;
        int wayCnt = q.front().wayCnt;
        q.pop();

        if(y == N-1 && x == M-1) {
            cout << wayCnt << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int my = y + dy[i];
            int mx = x + dx[i];

            if(my < 0 || my >= N || mx < 0 || mx >= M)
                continue;

            if(visited[my][mx][wallCnt])
                continue;

            //1은 이동할 수 없는 벽
            if(map[my][mx] == 1) {
                if(wallCnt < K) {
                    visited[my][mx][wallCnt+1] = true;
                    q.push({my, mx, wallCnt+1, wayCnt+1});
                }
                continue;
            }
            visited[my][mx][wallCnt] = true;
            q.push({my, mx, wallCnt, wayCnt+1});
        }
    }

    cout << "-1\n";

}
