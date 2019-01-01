#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

int N, K; // 수빈이가 있는 위치 N, 동생이 있는 위치 K
vector<bool> visited;
int second = 0;

void bfs() {
    queue<int> q;
    q.push(N);
    
    while(!q.empty()) {
        int queSize = q.size();
        
        for(int i = 0 ; i < queSize; i++) {
            int head = q.front();
            q.pop();
            
            if(head == K)
                return;
            
            if(head > 0 && visited[head-1] == 0) {
                q.push(head-1);
                visited[head-1] = 1;
            }
            
            if(head < MAX-1 && visited[head+1] == 0) {
                q.push(head+1);
                visited[head+1] = 1;
            }
            
            if(head * 2 <= MAX-1 && visited[head*2] == 0) {
                q.push(head*2);
                visited[head*2] =1;
            }
        }
        second = second + 1;
    }
}

int main() {
    
    cin >> N >> K;
    visited.resize(MAX);
    bfs();
    cout << second << endl;

    return 0;
}
