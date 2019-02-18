#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define MAX 101

int N, K, L;
int map[MAX][MAX]; //사과는 2, 뱀은 1, 맵은 0
vector<pair<int, int>> order;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int turn(int now, int next) {
    if(next == 0) {
        if(now == 0 || now == 1)
            return (now+2) % 4;
        else
            return 3-now;
    }
    
    else {
        if(now == 0 || now == 1)
            return 3- now;
        else
            return (now+2) % 4;
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> K;
    
    for(int i = 0; i < K; i++) {
        int kx, ky;
        cin >> kx >> ky;
        map[kx-1][ky-1] = 2;
    }
    
    cin >> L;
    
    for(int i = 0; i < L; i++) {
        int X;
        char C;
        
        cin >> X >> C;
        
        int d;
        if(C == 'L') // 왼쪽 0
            d = 0;
        else // 오른쪽1
            d = 1;
        
        order.push_back(make_pair(X, d));
    }
    
    vector<pair<int, int>> snake;
    
    int x = 0, y = 0; //머리 위치
    int d = 3;
    int sec = 0;
    
    int vi = 0; //시간 벡터 인덱스
    bool v_flag = false;
    
    map[x][y] = 1;
    snake.push_back(make_pair(x, y));
    
    while(true) {
        if(!v_flag && sec == order[vi].first) {
            d = turn(d, order[vi++].second);
            if(vi == order.size())
                v_flag = true;
        }
        
        int mx = x + dx[d];
        int my = y + dy[d];
        
        if(mx < 0 || my < 0 || mx >= N || my >= N)
            break;
        
        if(map[mx][my] == 1) {
            break;
        }
        
        else if(map[mx][my] == 0) {
            map[snake[0].first][snake[0].second] = 0;
            snake.erase(snake.begin());
        }
        
        x = mx;
        y = my;
        
        map[x][y] = 1;
        snake.push_back(make_pair(x, y));
        
        sec++;
    }
    
    cout << sec + 1;
    
    return 0;
}
