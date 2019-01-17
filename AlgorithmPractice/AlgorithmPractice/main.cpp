/*
 문제
 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
 
 입력
 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
 
 출력
 첫째 줄에 연결 요소의 개수를 출력한다.
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int N, M; //정점 간선 개수
int u, v; //간선 양 끝점

int edge[MAX][MAX];
bool visited[MAX];

void dfs(int cur) {
    visited[cur] = true;
    
    for(int i = 1; i <= N; i++) {
        if(edge[cur][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    cin >> N >> M;
    
    int cnt = 0;
    
    for(int i = 1; i <= M; i++) {
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
