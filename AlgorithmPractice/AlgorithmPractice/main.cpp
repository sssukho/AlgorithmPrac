#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1001

int N, M; //세로, 가로
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int edge[MAX][MAX];
int visited[MAX][MAX];

int emptyCell = 0;
int ripped = 0;
int basketSize;

queue<pair<int, int>> q;

bool allRipped() {
    int cnt = 0;
    
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j< M; j++) {
            if(edge[i][j] == 1)
                cnt++;
        }
    }
    
    if(cnt == basketSize-emptyCell)
        return true;
    
    return false;
}

int bfs() {
    int dayCnt = 0;
    
    while(!q.empty()) {
        int queSize = q.size();
        
        for(int i = 0; i < queSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int j = 0; j < 4; j++) {
                int my = y + dy[j];
                int mx = x + dx[j];
                
                if(my >= 0 && my < N && mx >= 0 && mx < M) {
                    if(edge[my][mx] == 0) {
                        edge[my][mx] = 1;
                        q.push(make_pair(my, mx));
                    }
                    
                }
            }
            //하나도 남김없이 다 익었는지
            if(q.size() == 0 && allRipped())
                return dayCnt;
            
            //익힐거는 다 익혔는데 익힐 수 없는거 있으면
            if(q.size() == 0 && !allRipped())
                return -1;
        }
        dayCnt++;
    }
    
    
    
    return dayCnt;
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> M >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> edge[i][j];
            if(edge[i][j] == -1)
                emptyCell++;
            if(edge[i][j] == 1) {
                ripped++;
                q.push(make_pair(i, j));
            }
        }
    }
    
    basketSize = N * M;
    if(basketSize-emptyCell == ripped) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << bfs() << endl;
    
    return 0;
}
