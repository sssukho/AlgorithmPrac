#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2]; //마지막 2는 벽 뚫기 여부

void bfs() {
    queue<pair<pair<int,int>, bool>> q; // (y,x), 벽뚫기
    q.push(make_pair(make_pair(0, 0), 1));
    cache[0][0][1] = 1;

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool block = q.front().second;
        q.pop();

        //도착하면
        if(y == N-1 && x == M-1) {
            cout << cache[y][x][block] << endl;
            return;
        }

        for(int i = 0; i< 4; i++) {
            int my = y + dy[i];
            int mx = x + dx[i];

            if(0 <= my && my < N && 0 <= mx && mx < M) {
                //벽이 있고, 벽을 아직 안 뚫었다면ㄴ
                if(graph[my][mx] == 1 && block) {
                    cache[my][mx][0] = cache[y][x][1]+1;
                    q.push(make_pair(make_pair(my, mx), 0));
                }
                //벽이 없고 방문하지 않았던 곳이라면
                else if(graph[my][mx] == 0 && cache[my][mx][block] == 0) {
                    cache[my][mx][block] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(my, mx), block));
                }
            }
        }
    }

    cout << "-1\n";
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    bfs();

    return 0;
}
