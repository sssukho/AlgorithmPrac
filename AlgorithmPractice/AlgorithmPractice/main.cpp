#include <iostream>
using namespace std;
#define MAX 51

int N, M;
int map[MAX][MAX];
int y, x, dir;
int ans;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int getBackDir(int dir) {
    if(dir == 0)
        return 2;
    else if(dir == 1)
        return 3;
    else if(dir == 2)
        return 0;
    else
        return 1;
}

int getDir(int dir) {
    if(dir == 0)
        return 3;
    else if(dir == 1)
        return 0;
    else if(dir == 2)
        return 1;
    else
        return 2;
}


int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    cin >> y >> x >> dir;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
    
    while(true) {
        //현재 위치 청소
        if(map[y][x] == 0) {
            map[y][x] = 2;
            ans++;
        }
        
        //큰 2번으로 다시 돌아가는 flag
        int check = 0;
        for(int i = 0; i < 4; i++) { //2.2
            dir = getDir(dir);
            int my = y + dy[dir];
            int mx = x + dx[dir];
            
            if(map[my][mx] == 0) { //2.1
                y = my;
                x = mx;
                check = 1; //2번 돌아가는 flag
                break;
            }
        }
        if(check == 1)
            continue;
        //2.3 후진하기
        int backDir = getBackDir(dir);
        
        y = y + dy[backDir];
        x = x + dx[backDir];
        
        //2.4 끝
        if(map[y][x] == 1)
            break;
    }
    
    cout << ans << endl;
}
