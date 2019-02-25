//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int n1, n2;
//string g1, g2;
//int T;
//
//int main() {
//    cout << "start" << endl;
//    cin.tie(0);
//    ios::sync_with_stdio(0);
//
//    cin >> n1 >> n2 >> g1 >> g2 >> T;
//    reverse(g1.begin(), g1.end());
//    string result = g1 + g2;
//
//    int g1size = (int)g1.size();
//    int g2size = (int)g2.size();
//
//    cout << result << endl;
//
//    for(int t = 1; t <= T; t++) {
//        for(int i = g1size-t; i <= g1size-1+t; i++) {
//            if(g1.find(result[i]) < g1size && g2.find(result[i+1]) < g2size) {
//                swap(result[i], result[i+1]);
//            }
//        }
//    }
//
//
//
//    cout << "------------" << endl;
//    cout << result << endl;
//
//
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10001

int N, M;
vector<int> edge[MAX];
bool visited[MAX];
int cnt;

void dfs(int nodeNum) {
    visited[nodeNum] = true;
    
    for(int i = 0; i < edge[nodeNum].size(); i++) {
        int next = edge[nodeNum][i];
        
        if(!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[b].push_back(a);
    }
    
    int nodeCnt = 0;
    vector<int> result;
    
    for(int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        cnt = 0;
        
        dfs(i);
        
        if(nodeCnt == cnt)
            result.push_back(i);
        if(nodeCnt < cnt) {
            nodeCnt = cnt;
            result.clear();
            result.push_back(i);
        }
    }
    
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
