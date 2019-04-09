#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

struct pos {
    int y;
    int x;
    int len;
};

int N, L; //size, 경사로 길이
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pos> q;
int ans = 0;

void colCheck() {
    for(int i = 0; i < N; i++)
        q.push({0, i, 1});
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int len = q.front().len;
        q.pop();
        
        if(y+1 >= N){
            ans++;
            continue;
        }
        
        if(abs(map[y+1][x]-map[y][x]) >= 2)
            continue;
        
        if(map[y+1][x] == map[y][x])
            q.push({y+1, x, len+1});
        
        //내려갈때
        if(map[y+1][x] - map[y][x] == -1) {
            if(y+L >= N)
                continue;
            
            int len_cnt = 0;
            int diff = map[y+1][x] - map[y][x];
            for(int i = 1; i <= L; i++) {
                if(map[y+i][x] - map[y][x] == diff) {
                    len_cnt++;
                }
            }
            
            if(len_cnt == L)
                q.push({y+L, x, 0});
        }
        
        //올라갈때
        if(map[y+1][x] - map[y][x] == 1) {
            if(len >= L)
                q.push({y+1, x, 1});
        }
    }
}

void rowCheck() {
    for(int i = 0; i < N; i++)
        q.push({i, 0, 1});
    
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int len = q.front().len;
        q.pop();
        
        if(x+1 >= N){
            ans++;
            continue;
        }
        
        if(abs(map[y][x+1]-map[y][x]) >= 2)
            continue;
        
        if(map[y][x+1] == map[y][x])
            q.push({y, x+1, len+1});
        
        //내려갈때
        if(map[y][x+1] - map[y][x] == -1) {
            if(x+L >= N)
                continue;
            
            int len_cnt = 0;
            int diff = map[y][x+1] - map[y][x];
            
            for(int i = 1; i <= L; i++) {
                if(map[y][x+i] - map[y][x] == diff) {
                    len_cnt++;
                }
            }
            
            if(len_cnt == L)
                q.push({y, x+L, 0});
        }
        
        //올라갈때
        if(map[y][x+1] - map[y][x] == 1) {
            if(len >= L)
                q.push({y, x+1, 1});
        }
    }
}

int main() {
    cout << "start" << endl;
    cin >> N >> L;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    colCheck();
    rowCheck();
    cout << ans << endl;
    return 0;
}
