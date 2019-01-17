/*
 입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
 
 각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 301
#define INF 987654321

int T; //테스트 케이스 수
int L; //체스판의 한 변의 길이

bool visited[MAX][MAX];
int cache[MAX][MAX];
int cy, cx; //나이트가 현재 있는 칸
int my, mx; //나이트가 이동하려고 하는 칸

int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void initCache() {
    for(int i = 0; i < MAX; i++)
        for(int j = 0 ; j < MAX; j++)
            cache[i][j] = INF;
}

int bfs(int curY, int curX) {
    initCache();
    
    queue<pair<int, int>> q;
    q.push(make_pair(curY, curX));
    cache[curY][curX] = 0;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == my && x == mx)
            return cache[y][x];
        
        for(int i = 0; i < 8; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(yy >= 0 && yy < L && xx >= 0 && xx < L) {
                if(!visited[yy][xx]) {
                    visited[yy][xx] = true;
                    q.push(make_pair(yy, xx));
                    cache[yy][xx] = min(cache[yy][xx], cache[y][x] + 1);
                }
            }
        }
    }
    
    return 0;
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> T;
    for(int i = 0; i < T; i++) {
        memset(visited, false, sizeof(visited));
        
        cin >> L;
        cin >> cy >> cx;
        cin >> my >> mx;
        
        cout << bfs(cy, cx) << endl;
    }
    return 0;
}
