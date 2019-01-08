/*
 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.
 한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.
 
 [입력]
 첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. N과 M은 3 이상 300 이하이다.
 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0 이상 10 이하이다.
 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다
 
 [출력]
 첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

#define MAX 301

int N, M; //세로, 가로
int yearCnt = 0;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int edge[MAX][MAX];
int mountain[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int y, int x) {
    visited[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];

        if(my > 0 && my < MAX-1 && mx > 0 && mx < MAX-1) {
            if(!visited[my][mx] && edge[my][mx] != 0) {
                dfs(my, mx);
            }
        }
    }

}

void melt() {
    memset(mountain, 0, sizeof(mountain));
    memcpy(mountain, edge, sizeof(edge));

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < M-1; j++) {
            if(mountain[i][j] != 0) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int my = i + dy[k];
                    int mx = j + dx[k];

                    if(mountain[my][mx] == 0)
                        cnt++;
                }

                edge[i][j] = max(mountain[i][j] - cnt, 0);
            }
        }
    }
}

int main() {
    //cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> edge[i][j];
            if(i == 0 || i == N-1 || j == 0 || j == M-1)
                edge[i][j] = 0;
        }
    }

    while(true) {
        memset(visited, false, sizeof(visited));

        bool isStopped = false;

        int groupCnt = 0;
        
        for(int i = 1; i < N-1; i++) {
            for(int j = 1; j < M-1; j++) {
                if(!visited[i][j] && edge[i][j] != 0) {
                    groupCnt++;

                    if(groupCnt == 2) {
                        isStopped = true;
                        break;
                    }

                    dfs(i, j);
                }
            }
        }
        if(isStopped)
            break;

        if(groupCnt == 0) {
            yearCnt = 0;
            break;
        }

        melt();
        yearCnt++;
    }

    cout << yearCnt << endl;
    return 0;
}
