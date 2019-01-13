#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 101

int edge[MAX][MAX];
bool visited[MAX][MAX];

int N, M; //세로, 가로

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(int cy, int cx) {
    //edge[cy][cx] = 2;
    visited[cy][cx] = true;
    q.push(make_pair(cy, cx));
    
    while(!q.empty()) {
        int queSize = q.size();
        
        for(int i = 0; i < queSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            if(y == M-1 && x == N-1)
                return;
            
            for(int j = 0; j < 4; j++) {
                int my = y + dy[j];
                int mx = x + dx[j];
                
                if(my >= 0 && my < N && mx >= 0 && mx < M) {
                    if(!visited[my][mx] && edge[my][mx] == 1) {
                        visited[my][mx] = true;
                        q.push(make_pair(my, mx));
                        edge[my][mx] = edge[y][x] + 1;
                    }
                }
            }
            
            
        }
    }
}

int main() {
    cout << "start" << endl;
    
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &edge[i][j]);
    
    bfs(0, 0);
    cout << edge[N-1][M-1] << endl;
    
    return 0;
}
