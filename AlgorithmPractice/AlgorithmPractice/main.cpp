/*
 첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)
 
 각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).
 
 다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)
 
 송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)
 
 */

//50미터에 한 병씩 먹고
//편의점에 들렀을 때 빈병은 버리고 새 맥주 병을 살 수 있다.
//박스에 들어있는 맥주는 20병을 넘을 수 없다.
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 70000

int T; // 테스트 케이스 수
int N; // 매궂를 파는 편의점의 개수
int sy, sx; // 상근이네 집
int py, px; // 편의점
int fy, fx; // 락페

int edge[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool isHappy = false;
int beerBox = 20;

int ySize = 0, xSize = 0;

void dfs(int y, int x) {
    
    if(y == fy && x == fx) {
        if(beerBox >= 0)
            isHappy = true;
        return;
    }
    
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= sy && my < fy && mx >= sx && mx < fx) {
            //그냥 갈 수 있는 길이면
            if(!visited[my][mx] && edge[my][mx] == 0) {
                dist[my][mx] = (mx-x) + (my-y);
                if(dist[my][mx] >= 50) {
                    dist[my][mx] = 0;
                    beerBox--;
                }
                visited[my][mx] = true;
                dfs(my, mx);
            }
            //편의점인 경우
            else if(!visited[my][mx] && edge[my][mx] == 1) {
                visited[my][mx] = true;
                beerBox = 20;
                dfs(my, mx);
            }
        }
        
        if(beerBox <= 0) {
            isHappy = false;
            return;
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> T;
    for(int i = 0; i < T; i++) {
        memset(edge, 0, sizeof(edge));
        memset(visited, 0, sizeof(visited));
        cin >> N;
        cin >> sx >> sy;
        edge[sy][sx] = 2; //상근이의 현재 위치
        for(int j = 0; j < N; j++) {
            cin >> px >> py;
            edge[py][px] = 1; //편의점
        }
        cin >> fx >> fy;
        edge[fy][fx] = 3;//페스티벌 위치
    }
    
    ySize = fy-sy;
    xSize = fx-sx;
    
    for(int i = sy; i < fy; i++) {
        for(int j = sx; j < fx; j++) {
            if((!visited[i][j] && edge[i][j] == 1) || edge[i][j] == 2) {
                dfs(i, j);
                beerBox = 20;
            }
        }
    }
    
    if(isHappy)
        cout << "happy" << endl;
    else
        cout << "sad" << endl;
    
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 100 + 2; //출발점, 도착점 포함

int N;
vector<int> graph[MAX];
bool visited[MAX];

//맨해튼 거리
int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

//전형적인 DFS
void DFS(int node){
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (visited[next] == false)
            DFS(next);
    }
}

int main(void){
    cout << "start" << endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상
    
    int test_case;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++)
    {
        for (int j = 0; j < MAX; j++)
            graph[j].clear();
        memset(visited, false, sizeof(visited));
        
        cin >> N;
        
        vector<pair<int, int>> coord;
        
        
        
        //출발점(0), 도착점(N + 1) 포함
        
        for (int j = 0; j < N + 2; j++)
            
        {
            
            int y, x;
            
            cin >> y >> x;
            
            
            
            coord.push_back(make_pair(y, x));
            
        }
        
        
        
        //맥주 20병으로 갈 수 있는 거리 내에 있으면 그래프에 추가
        
        for(int j=0; j<N+2; j++)
            
            for(int k=j+1; k<N+2; k++)
                
                if (distance(coord[j], coord[k]) <= 50 * 20)
                    
                {
                    
                    //양방향 그래프
                    
                    graph[j].push_back(k);
                    
                    graph[k].push_back(j);
                    
                }
        DFS(0);
        
        //0이 출발점, N+1이 도착점이므로
        if (visited[N + 1])
            cout << "happy\n";
        else
            cout << "sad\n";
        
    }
    
    return 0;
    
}
