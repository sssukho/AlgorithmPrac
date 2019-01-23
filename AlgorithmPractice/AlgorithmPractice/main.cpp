#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char map[12][6];
int num[73] = {0, };
int visited[12][6];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int idx = 0;

void dfs(int y, int x, char ch) {
    visited[y][x] = idx;
    num[idx]++;
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < 12 && mx >= 0 && mx < 6) {
            if(visited[my][mx] == 0 && map[my][mx] != '.' && map[my][mx] == map[y][x])
                dfs(my, mx, map[y][x]);
        }
    }
}


int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    bool puyo = true; //뿌요 1개이상 되는지
    while(puyo) {
        memset(visited, 0, sizeof(visited));
        memset(num, 0, sizeof(num));
        puyo = false;
        //탐색 : visit 체크(증가), puyo 체크, room 개수 증가
        idx = 1;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(map[i][j] != '.' && visited[i][j] == 0) {
                    dfs(i, j, map[i][j]);
                    idx++;
                }
            }
        }
        
        //num중에 4 이상이 있으면 뿌요 가능 -> map '.' 으로
        for(int k = 1; k <= idx; k++) {
            if(num[k] >= 4) {
                puyo = true;
                for(int i = 0; i < 12; i++) {
                    for(int j = 0; j < 6; j++) {
                        if(visited[i][j] == k)
                            map[i][j] = '.';
                    }
                }
            }
        }
        
        //한 column씩 밑으로 내려주기
        for(int j = 0; j < 6; j++) {
            vector<char> drop;
            for(int i = 11; i >= 0; i--) { //아래서부터
                if(map[i][j] != '.')
                    drop.push_back(map[i][j]);
            }
            int cnt = 0;
            for(int k = 11; k > 11-drop.size(); k--) {
                map[k][j] = drop[cnt++];
            }
            for (int k = 11-drop.size(); k>= 0; k--) {
                map[k][j] = '.';
            }
        }
        if(puyo) ans++;
        
    }
    cout << ans;
    return 0;
}
