#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000001

int N;
vector<int> friends[MAX]; // 처음 입력하는 친구 관계
vector<int> dirNode[MAX]; // 단방향 그래프 저장
bool visited[MAX];
int cache[MAX][2]; //노드, earlyAdopter?

void dfs(int node) {
    visited[node] = true;
    
    for(int i = 0; i < (int)friends[node].size(); i++) {
        int next = friends[node][i];
        
        if(!visited[next]) {
            dirNode[node].push_back(next);
            dfs(next);
        }
    }
}

int getEarlyAdopter(int node, bool isEarlyAdopter) {
    int &result = cache[node][isEarlyAdopter];
    if(result != -1)
        return result;
    
    //본인이 얼리어댑터이면 자식은 어떻든 상관 없다.
    if(isEarlyAdopter) {
        result = 1; //얼리 어댑터이므로
        for(int i = 0; i < (int)dirNode[node].size(); i++) {
            int next = dirNode[node][i];
            result += min(getEarlyAdopter(next, true), getEarlyAdopter(next, false));
        }
    }
    
    //본인이 얼리어댑터가 아니면 자식은 무조건 얼리어댑터여야 한다.
    else {
        result = 0; //얼리어댑터가 아니므로
        for(int i = 0; i < (int)dirNode[node].size(); i++) {
            int next = dirNode[node][i];
            result += getEarlyAdopter(next, true);
        }
    }
    
    return result;
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 0; i < N - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        friends[node1].push_back(node2);
        friends[node2].push_back(node1);
    }
    
    memset(cache, -1, sizeof(cache));
    
    dfs(1); //1이 루트
    
    //루트가 얼리어댑터일 수도 아닐 수도 있으므로
    cout << min(getEarlyAdopter(1, false), getEarlyAdopter(1, true)) << endl;
    
    return 0;
}

//자신이 얼리어답터인 경우 -> 자식들은 얼리 어답터가 아니어도 된다.
//자신이 얼리어답터가 아닌 경우 -> 이웃한 모두가 얼리어답터여야 한다.
