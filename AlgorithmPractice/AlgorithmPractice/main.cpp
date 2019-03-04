#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <memory.h>
#include <algorithm>
using namespace std;
#define MAX 9

int N, M; //세로 가로
int map[MAX][MAX];
int copyMap[MAX][MAX];
vector<pair<int, int>> virus; //y, x
vector<pair<int, int>> empty; //y, x
int emptySize = 0;
int emptyCnt;
int ans = 0;

vector<int> comb;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

//바이러스 퍼지게 하는 dfs
void dfs(int y, int x) {
    copyMap[y][x] = 2;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < N && mx >= 0 && mx < M) {
            if(copyMap[my][mx] == 0) {
                dfs(my, mx);
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    
    //0은 빈칸, 1은 벽, 2는 바이러스
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push_back(make_pair(i, j));
            
            if(map[i][j] == 0) {
                emptySize++;
                empty.push_back(make_pair(i, j));
            }
            
        }
    }
    
    for(int i = 0; i < 3; i++)
        comb.push_back(1);
    
    for(int i = 0; i < emptySize-3; i++)
        comb.push_back(0);
    
    sort(comb.begin(), comb.end());
    
    do {
        emptyCnt = 0;
        memcpy(copyMap, map, sizeof(map));
        
        //벽 세워보기
        for(int i = 0 ; i < emptySize; i++) {
            if(comb[i] == 1) {
                int y = empty[i].first;
                int x = empty[i].second;
                copyMap[y][x] = 1;
            }
        }
        
        //바이러스 퍼지게
        for(int i = 0; i < (int)virus.size(); i++) {
            int y = virus[i].first;
            int x = virus[i].second;
            
            dfs(y, x);
        }
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(copyMap[i][j] == 0)
                    emptyCnt++;
        
        ans = max(ans, emptyCnt);
        
    }while(next_permutation(comb.begin(), comb.end()));
    
    cout << ans << endl;
    
    return 0;
}

//벽을 다 세워봐야함
//0인 벽의 카운ㄴㅌ
