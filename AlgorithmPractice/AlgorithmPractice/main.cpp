/*
 -> dfs 혹은 bfs로 단지번호를 붙이고 단지 최대 갯수 출력
 -> 벽을 허무는 경우를 벽마다 일일이 검사하는 것보다 붙어있는 단지번호가 서로 다를 경우
    서로 다른 수일 경우 두개의 단지 개수를 합한 것이 벽 1개를 허물고 만들 수 있는 벽의 크기가 될 수 있음 (벽을 허물고 단지 번호 다시 붙이는 것보다 빠름)
 -> 서로 붙어있지만 다른 단지번호의 합 중에 최고가 벽을 허물고 만들 수 있는 최대 벽의 크기
 */

#include <iostream>
using namespace std;

int n, m, map[51][51], visit[51][51], mx, add, arr[2500];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y, int num) {
    visit[x][y] = num;
    for(int i = 0; i < 4; i++) {
        
        if((map[x][y] & (1<<i)) == 0) { //벽이 없는 경우
            int mx = x + dx[i];
            int my = y + dy[i];
            
            if(mx < 0 || mx >= m || my < 0 || my >= n || visit[mx][my] != 0)
                continue;
            dfs(mx, my, num);
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    //단지 번호 붙이기
    int num = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j] == 0) {
                dfs(i, j, num);
                num++;
            }
        }
    }
    
    //최대 단지 개수 구하기
    num -= 1; mx = 0; add = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            arr[visit[i][j]]++;
        }
    }
    
    for(int i=1; i <= num; i++) {
        if(mx<arr[i]) {
            mx = arr[i];
        }
    }
    
    //붙어있는 단지 비교하기
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                int tx = i + dx[k];
                int ty = j + dy[k];
                
                if(tx >= 0 && tx < m && ty >= 0 && ty < n) {
                    if(visit[i][j] != visit[tx][ty]) {
                        int a = arr[visit[i][j]] + arr[visit[tx][ty]];
                        if(add < a)
                            add = a;
                    }
                }
            }
        }
    }
    
    cout << num << "\n" << mx << "\n" << add << "\n";
    return 0;
}
