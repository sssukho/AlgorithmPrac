#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 101

int M, N, H; //가로, 세로, 높이

int edge[MAX][MAX][MAX]; //세로, 가로, 층수 순
bool visited[MAX][MAX][MAX]; //세로, 가로, 층수 순

//1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 들어있지 않은 칸

int rippedTomato = 0;
int basketCnt = 0;
int notRipped = 0;

int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

queue<pair<pair<int, int>, int>> q;

bool allRipped() {
    int possible = M*N*H-notRipped;
    int cnt = 0;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(edge[j][k][i] == 1)
                    cnt++;
            }
        }
    }
    
    return possible == cnt;
}

int bfs() {
    int cnt = 0;
    
    //처음부터 익힐 수 있는 토마토가 없는 경우
    if(q.empty())
        return -1;
    
    while(!q.empty()) {
        int queSize = q.size();
        
        for(int i = 0; i < queSize; i++) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int h = q.front().second;
            q.pop();
            
            for(int j = 0; j < 6; j++) {
                int my = y + dy[j];
                int mx = x + dx[j];
                int mh = h + dh[j];
                
                if(my >= 0 && my < N && mx >= 0 && mx < M && mh >= 0 && mh < H) {
                    if(edge[my][mx][mh] == 0) { //토마토 안 익었을 경우에만
                        edge[my][mx][mh] = 1;
                        q.push(make_pair(make_pair(my, mx), mh));
                    }
                }
            }
            
            
            //익힐 수 있는 토마토를 전부 익혔고 전부 익었을 경우
            if(q.size() == 0 && allRipped())
                return cnt;
            //익힐 수 있는 토마토는 전부 익혔지만 안 익은 토마토 존재
            else if(q.size() == 0 && !allRipped())
                return -1;
        }
        cnt++;
    }
    
    return cnt;
}


int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> M >> N >> H;
    basketCnt = M * N * H;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> edge[j][k][i];
                if(edge[j][k][i] == 1)
                    q.push(make_pair(make_pair(j, k), i)); //익은 토마토는 큐에
                else if(edge[j][k][i] == -1) //토마토 넣을 수 없는 칸
                    notRipped++;
            }
        }
    }
    
    if(q.size() == basketCnt - notRipped)
        cout << 0 << endl; //모든 토마토 다 익었을 경우
    else
        cout << bfs() << endl;
    
    return 0;
}
