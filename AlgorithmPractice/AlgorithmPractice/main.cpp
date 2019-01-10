/*
 [문제]
 여러 섬으로 이루어진 나라가 있다. 이 나라의 대통령은, 섬들을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다. 하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.
 
 이 나라는 N×N크기의 이차원 평면상에 존재한다. 이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다. 다음은 세 개의 섬으로 이루어진 나라의 지도이다.
 
 
 위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다. 가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.
 
 물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).
 
 지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.
 
 [입력]
 첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다. 항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.
 
 [출력]
 첫째 줄에 가장 짧은 다리의 길이를 출력한다.
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 101
#define INF 987654321

int N; // 지도 크기

int edge[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x, int islandNum) {
    visited[y][x] = true;
    edge[y][x] = islandNum;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < MAX && mx >= 0 && my < MAX) {
            if(!visited[my][mx] && edge[my][mx])
                dfs(my, mx, islandNum);
        }
    }
}

int bfs(int islandNum) {
    queue<pair<int, int>> q;
    
    //우선 해당 섬의 좌표를 다 큐에 넣는다.(y,x)
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(edge[i][j] == islandNum) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    
    int result = 0;
    
    while(!q.empty()) {
        int queSize = q.size();
        
        //현재 큐에 있는 칸으로부터 한칸씩 전진해본다.
        for(int i = 0; i < queSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int my = y + dy[i];
                int mx = x + dx[i];
                
                //범위 내에 있고
                if(my >= 0 && my < N && mx >= 0 && mx < N) {
                    //다른 섬에 도착할 경우 반환
                    if(edge[my][mx] && edge[my][mx] != islandNum)
                        return result;
                    //아직 방문하지 않은 바다칸이면 방문했다고 표시 후 큐에 넣는다.
                    else if(edge[my][mx] == 0 && !visited[my][mx]) {
                        visited[my][mx] = true;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        }
        result++;
    }
    
    return result;
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> edge[i][j];
        }
    }
    
    int islandNum = 1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && edge[i][j]) {
                dfs(i, j, islandNum++);
            }
        }
    }
    
    int result = INF;
    
    for(int i = 1; i < islandNum; i++) {
        memset(visited, false, sizeof(visited));
        result = min(result, bfs(i));
        
    }
    
    cout << result << endl;
    
    return 0;
}


/*
 1. dfs 이용해서 각 섬에 번호를 붙여준다.
 2. bfs 이용해서 각 섬간의 최소 거리를 구한다.
 3. 각 섬간의 최소거리를 vector에 다 push 해두었다가 오름차순으로 정렬해준다. (sort 메소드는 default가 오름차순)
 4. 최소 거리가 저장된 vector에서 가장 첫 번째 값을 꺼내온다.
*/
