#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 55

int N, maxEat;
char map[MAX][MAX];
//우측 아래로만 보면 되기 때문
int dy[2] = {1, 0};
int dx[2] = {0, 1};

int check() {
    int ret = 1;
    int cnt = 1;
    
    for(int i = 0; i < N; i++) {
        //가로
        for(int j = 0; j < N-1; j++) {
            if(map[i][j] == map[i][j+1])
                cnt++;
            else {
                ret = max(ret,cnt);
                cnt = 1;
            }
        }
        
        ret = max(ret, cnt);
        cnt = 1;
        //세로
        for(int j = 0; j < N-1; j++) {
            if(map[j][i] == map[j+1][i])
                cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
        cnt = 1;
    }
    
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            for(int i = 0; i < 2; i++) {
                int my = y + dy[i];
                int mx = x + dx[i];
                
                if(!map[my][mx]) continue;
                swap(map[y][x], map[my][mx]);
                maxEat = max(maxEat, check());
                swap(map[y][x], map[my][mx]);
            }
        }
    }
    
    cout << maxEat << endl;
    
    return 0;
}
