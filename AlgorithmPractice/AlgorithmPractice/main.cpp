#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
#define MAX 50

int R, C; //세로 가로
string map[MAX];
int time_way[MAX][MAX] = { 0, };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int startY, startX;
int destY, destX;

queue<pair<int, int>> coord;

void makeWater() {
    int coordSize = (int)coord.size();
    
    for (int i = 0; i < coordSize; i++) {
        int y = coord.front().first;
        int x = coord.front().second;
        coord.pop();
        
        for (int i = 0; i < 4; i++) {
            int my = y + dy[i];
            int mx = x + dx[i];
            
            if (my >= 0 && my < R && mx >= 0 && mx < C) {
                if (map[my][mx] != 'X' && map[my][mx] != 'D' && map[my][mx] != '*') {//S도 될수 있음
                    map[my][mx] = '*';
                    coord.push(make_pair(my, mx));
                }
            }
        }
    }
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(startY, startX));
    
    time_way[startY][startX] = 1;
    makeWater();
    
    int qn = (int)q.size();
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == destY && x == destX)
            return true;
        
        for (int i = 0; i < 4; i++) {
            int my = y + dy[i];
            int mx = x + dx[i];
            
            if (my >= 0 && my < R && mx >= 0 && mx < C) {
                if(time_way[my][mx]==0){
                    if (map[my][mx] == '.' || map[my][mx] == 'D') {
                        time_way[my][mx] = time_way[y][x] + 1;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        }
        
        //1초... 큐마다 도는게 아니라..
        qn--;
        if (qn == 0) {
            qn = (int)q.size();
            makeWater();
        }
    }
    
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        cin >> map[i];
        
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'S') {
                startY = i;
                startX = j;
            }
            if (map[i][j] == 'D') {
                destY = i;
                destX = j;
            }
            if (map[i][j] == '*') {
                coord.push(make_pair(i, j));
            }
        }
    }
    if (bfs())
        cout << time_way[destY][destX]-1;
    else
        cout << "KAKTUS";
    
    return 0;
}
