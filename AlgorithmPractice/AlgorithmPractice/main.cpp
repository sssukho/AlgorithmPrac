#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 101

int map[MAX][MAX];
bool visited[MAX][MAX];

int N;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int min_height = 100;
int max_height = 0;

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < N && mx >= 0 && mx < N) {
            if(!visited[my][mx] && map[my][mx] > min_height) {
                visited[my][mx] = true;
                dfs(my, mx);
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] < min_height)
                min_height = map[i][j];
            if(map[i][j] > max_height)
                max_height = map[i][j];
        }
    }
    int ans = 1;
    while(min_height < max_height) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        
        for(int i = 0 ; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(min_height < map[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        ans = max(ans,cnt);
        min_height++;
    }
    
    
    cout << ans << endl;
    
    return 0;
}
