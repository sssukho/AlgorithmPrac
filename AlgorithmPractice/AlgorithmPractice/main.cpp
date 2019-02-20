#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
#define MAX 102

int T;
int H, W;
string map[MAX];
bool visited[MAX][MAX];
bool key[26];
int ans;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void simulation(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        //범위 벗어남
        if(curY < 0 || curY > H+1 || curX < 0 || curX > W+1)
            continue;
        
        //이미 방문한 지점이거나, 벽이거나, 잠긴 문일 경우
        if(visited[curY][curX] || map[curY][curX] == '*' || ('A' <= map[curY][curX] && map[curY][curX] <= 'Z'))
            continue;
        
        visited[curY][curX] = true; //방문 표시
        
        //문서
        if(map[curY][curX] == '$') {
            ans++;
            map[curY][curX] = '.';
        }
        
        //열쇠 찾았을 경우
        if('a' <= map[curY][curX] && map[curY][curX] <= 'z') {
            char door = (char)toupper(map[curY][curX]);
            map[curY][curX] = '.';
            
            //이미 있던 열쇠에 대해선는 처리하지 않늗나.
            if(key[(int)door - 65] == false) {
                key[(int)door-65] = true;
                //잠긴 문을 연다.
                for(int y = 1; y <= H; y++)
                    for(int x = 1; x <= W; x++)
                        if(map[y][x] == door)
                            map[y][x] = '.';
                //잠긴 문이 열렸으므로 모든 경로를 다시 확인
                memset(visited, false, sizeof(visited));
                while(!q.empty())
                    q.pop();
                q.push(make_pair(curY, curX));
                continue;
            }
        }
        for(int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            q.push(make_pair(nextY, nextX));
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        memset(key, false, sizeof(key));
        
        cin >> H >> W;
        
        //테두리를 빈칸으로
        for(int i = 0; i < W + 2; i++) {
            map[0] += '.';
        }
        
        for(int i = 1; i <= H; i++) {
            string temp;
            cin >> temp;
            map[i] += '.';
            map[i] += temp;
            map[i] += '.';
        }
        
        for(int i = 0; i < W + 2; i++) {
            map[H+1] += '.';
        }
        
        string inputKey;
        cin >> inputKey;
        
        for(int i = 0; inputKey[i] != '0' && i < inputKey.length(); i++) {
            key[(int)inputKey[i]-97] = true; //열쇠 설정
            //문을 열어둔다.
            for(int y = 1; y <= H; y++) {
                for(int x = 1; x <= W; x++) {
                    if(map[y][x] == (char)toupper(inputKey[i]))
                        map[y][x] = '.';
                }
            }
        }
        
        ans = 0;
        simulation(0, 0);
        cout << ans << endl;
    }
    
    return 0;
}
