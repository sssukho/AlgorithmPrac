// 백준 2667번 flood fill
// https://www.acmicpc.net/problem/2667

/*
 <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 
 [입력]
 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
 
 [출력]
 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 3
 7
 8
 9
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 26

int N; // 정사각형 크기
int edge[MAX][MAX];
bool visited[MAX][MAX];

int groupCount = 0; // 단지 수
int homeCount = 0; // 단지 안에 있는 집 수

vector<int> sortedHomeCount; // 오름차순으로 정렬할 때 필요한 템플릿

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < N && mx >= 0 && mx < N) {
            if(edge[my][mx] == 1 && !visited[my][mx]) {
                homeCount = homeCount + 1;
                dfs(my, mx);
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &edge[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(edge[i][j] == 1 && !visited[i][j]) {
                homeCount++;
                dfs(i, j);
                groupCount++;
                sortedHomeCount.push_back(homeCount);
            }
            homeCount = 0;
        }
    }
    
    sort(sortedHomeCount.begin(), sortedHomeCount.end());
    
    cout << groupCount << endl;
    for(auto x : sortedHomeCount) {
        cout << x << endl;
    }
    
}
