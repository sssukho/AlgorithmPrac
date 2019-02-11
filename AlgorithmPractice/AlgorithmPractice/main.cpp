#include <iostream>
#include <queue>
using namespace std;
#define MAX 50

struct Minsik {
    int y;
    int x;
    int key;
};

int N, M; //세로 가로

bool visited[MAX][MAX][64];
char map[MAX][MAX];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<Minsik> q;

int destY, destX;
int cnt = 0;

bool isFinished = false;

void bfs() {
    while(!q.empty()) {
        int qSize = (int)q.size();
        
        for(int i = 0; i < qSize; i++) {
            int y = q.front().y;
            int x = q.front().x;
            int key = q.front().key;
            q.pop();
            
            if(y == destY && x == destX) {
                isFinished = true;
                return;
            }
            
            for(int j = 0; j < 4; j++) {
                int my = y + dy[j];
                int mx = x + dx[j];
                
                if(my >= 0 && my < N && mx >= 0 && mx < M) {
                    if(!visited[my][mx][key]) {
                        //빈곳, 출구일때
                        if(map[my][mx] == '.' || map[my][mx] == '1' || map[my][mx] == '0') {
                            visited[my][mx][key] = true;
                            q.push({my, mx, key});
                        }
                        //열쇠일때
                        else if(map[my][mx] >= 'a'-0 && map[my][mx] <= 'f'-0) {
                            visited[my][mx][key] = true;
                            int kk = (1 << (map[my][mx]-'a')) | key;
                            visited[my][mx][kk] = true;
                            q.push({my, mx, kk});
                        }
                        //문일때
                        else if(map[my][mx] >= 'A'-0 && map[my][mx] <= 'F'-0) {
                            int isHaveKey = (1 << (map[my][mx]-'A')) & key;
                            if(isHaveKey > 0) {
                                visited[my][mx][key] = true;
                                q.push({my, mx, key});
                            }
                        }
                    }
                }
            }
        }
        cnt++;
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '1') {
                destY = i;
                destX = j;
            }
            if(map[i][j] == '0') {
                q.push({i, j, 0});
                visited[i][j][0] = true;
            }
        }
    }
    
    bfs();
    
    if(isFinished)
        cout << cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}
