#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1001

int N, M, V; // 정점의 개수 N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
int u, v; //u는 시작 정점, v는 도착 정점.

int edge[MAX][MAX];
bool visited[MAX];

void dfs(int cur) {
    visited[cur] = true;
    
    cout << cur << " ";
    
    for(int i = 1; i <= N; i++) {
        if(edge[cur][i] == 1 && !visited[i])
            dfs(i);
    }
}

void bfs(int cur) {
    queue<int> q;
    visited[cur] = true;
    q.push(cur);
    
    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for(int i = 1; i <= N; i++) {
            if(edge[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    
    dfs(V);
    memset(visited, false, sizeof(visited));
    cout << "\n";
    bfs(V);
    
}
