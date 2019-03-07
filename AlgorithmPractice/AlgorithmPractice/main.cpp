#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int N;
int cnt;

int node[MAX];
bool visited[MAX];
bool cycle[MAX];

bool DFS(int startNum, int nodeNum) {
    if(visited[nodeNum])
        return false;
    
    visited[nodeNum] = true;
    
    //사이클을 이루면
    if(startNum == nodeNum || DFS(startNum, node[nodeNum])) {
        cnt++;
        cycle[nodeNum] = true;
        return true;
    }
    return false;
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> node[i];
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            visited[j] = cycle[j]; //이미 사이클을 이루는 집합은 재방문X
        DFS(i, node[i]);
    }
    
    cout << cnt << endl;
    for(int i = 1; i <= N; i++)
        if(cycle[i]) //사이클 이루는 노드들 출력
            cout << i << " ";
    cout << endl;
    
    return 0;
}
