#include <iostream>
#include <cstring>
using namespace std;

#define MAX 51

int map[MAX][MAX];
bool visited[MAX][MAX];

int W, H; //너비, 높이 (가로 세로)

int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int cnt = 0;

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 8; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < H && mx >= 0 && mx < W) {
            if(!visited[my][mx] && map[my][mx] == 1) {
                visited[my][mx] = true;
                dfs(my,mx);
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    while(true) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        
        cin >> W >> H;
        if(W == 0 && H == 0)
            break;
        
        //1은 땅, 0은 바다
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }
        
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(!visited[i][j] && map[i][j] == 1) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
