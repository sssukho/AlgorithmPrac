#include <iostream>
using namespace std;
#define MAX 101

bool visited[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int M, N;

int main() {
    cout << "start" << endl;
    cin >> M >> N;
    
    int dir = 0;
    int y = 0, x = 0;
    visited[0][0] = true;
    int cnt = 0;
    bool isFinished = false;
    
    while(true) {
        y = y + dy[dir];
        x = x + dx[dir];
        
        if(y >= 0 && y < M && x >= 0 && x < N && !visited[y][x]) {
            visited[y][x] = true;
            isFinished = false;
        }
        
        else {
            if(isFinished)
                break;
            
            y = y - dy[dir];
            x = x - dx[dir];
            isFinished = true;
            dir = (dir+1) % 4;
            cnt++;
        }
    }
    
    cout << cnt - 1 << endl;
    
    return 0;
}
