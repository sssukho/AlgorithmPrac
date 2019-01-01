#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 51

int T, M, N, K, X, Y; //테스트 케이스 수, 배추밭의 가로길이, 세로길이, 배추가 심어져 있는 위치의 개수 K, 배추의 위치 X, Y
int edge[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if(edge[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

int main() {

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        memset(visited, false, sizeof(visited));
        memset(edge, 0, sizeof(edge));

        for(int j = 0; j < K; j++) {
            cin >> X >> Y;
            edge[Y][X] = 1;
        }

        int count = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(edge[j][k] == 1 && visited[j][k] == 0) {
                    count++;
                    dfs(j,k);

                }

            }
        }
        cout << count << "\n";
    }

    return 0;
}
