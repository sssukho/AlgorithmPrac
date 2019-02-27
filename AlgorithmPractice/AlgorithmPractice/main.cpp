#include <iostream>
using namespace std;
#define MAX 101

int N, M;
int map[MAX][MAX];
int dy[4] = { 1, -1, 0, 0};
int dx[4] = { 0, 0, 1, -1};

//치즈 개수 파악
int allMelted() {
    int cnt = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 1 || map[i][j] == 2) {
                //치즈인데 외부 공기에 2면 이상 닿지 않은 치즈들
                map[i][j] = 1;
                cnt++;
            }
            else map[i][j] = 0;
        }
    }
    
    return cnt;
}

//외부 공기로만 계속 들어감
void dfs(int y, int x) {
    map[y][x] = -1;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < N && mx >= 0 && mx < M) {
            if(map[my][mx] > 0)
                map[my][mx]++;
            else if(map[my][mx] == 0)
                dfs(my, mx);
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int time = 0;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    while(true) {
        int toMelt = allMelted();
        if(toMelt == 0)
            break;
        
        for(int i = 0; i < toMelt; i++) {
            dfs(0, 0);
        }
        
        time++;
    }
    cout << time << endl;
    return 0;
}
