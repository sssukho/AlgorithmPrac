/*
 문제
 통제 할 수 없는 미친 로봇이 평면위에 있다. 그리고 이 로봇은 N번의 행동을 취할 것이다.
 
 각 행동에서 로봇은 4개의 방향 중에 하나를 임의로 선택한다. 그리고 그 방향으로 한 칸 이동한다.
 
 로봇이 같은 곳을 한 번보다 많이 이동하지 않을 때, 로봇의 이동 경로가 단순하다고 한다. (로봇이 시작하는 위치가 처음 방문한 곳이다.) 로봇의 이동 경로가 단순할 확률을 구하는 프로그램을 작성하시오. 예를 들어, EENE와 ENW는 단순하지만, ENWS와 WWWWSNE는 단순하지 않다. (E는 동, W는 서, N은 북, S는 남)
 
 입력
 첫째 줄에 N, 동쪽으로 이동할 확률, 서쪽으로 이동할 확률, 남쪽으로 이동할 확률, 북쪽으로 이동할 확률이 주어진다. N은 14보다 작거나 같은 자연수이고,  모든 확률은 100보다 작거나 같은 자연수 또는 0이다. 그리고, 동서남북으로 이동할 확률을 모두 더하면 100이다.
 
 출력
 첫재 줄에 로봇의 이동 경로가 단순할 확률을 출력한다. 절대/상대 오차는 10-9 까지 허용한다.
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 31

int N; //입력받는 것들
double percent[4]; //percentage

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0 , 0, 1, -1};

bool visited[MAX][MAX];
double result = 0;

void dfs(int y, int x, int cnt, double prob) {
    if(cnt == N) {
        result = result + prob;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < MAX && mx >= 0 && mx < MAX) {
            if(!visited[my][mx]) {
                visited[my][mx] = true;
                dfs(my, mx, cnt+1, prob * percent[i]);
                visited[my][mx] = false;
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N;
    
    for(int i = 0; i < 4; i++) {
        cin >> percent[i];
        percent[i] = (double)percent[i] / 100;
    }
    
    visited[14][14] = true;
    dfs(14, 14, 0, 1);
    
    cout.precision(9);
    cout << result << endl;
    
    return 0;
}
