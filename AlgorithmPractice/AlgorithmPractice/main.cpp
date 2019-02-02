#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const long long MININF = -2e9;
const int MAX = 1000;

int N, M; //세로 가로
int Mars[MAX][MAX];
bool visited[MAX][MAX];
long long cache[3][MAX][MAX]; //왼쪽 오른쪽 아래

long long maxSum(int dir, int y, int x) { //방향, 세로, 가로
    //목적지 도달시
    if(y == N-1 && x == M-1)
        return Mars[y][x];
    
    long long &result = cache[dir][y][x];
    if(result != MININF)
        return result;
    
    visited[y][x] = true; //방문했다고 표시
    
    long long temp1 = MININF, temp2 = MININF, temp3 = MININF;
    
    //왼쪽
    if(x - 1 >= 0 && !visited[y][x-1])
        temp1 = maxSum(0, y, x-1);
    //오른쪽
    if(x + 1 < M && !visited[y][x+1])
        temp2 = maxSum(1, y, x+1);
    //아래
    if(y + 1 < N && !visited[y+1][x])
        temp3 = maxSum(2, y+1, x);
        
    visited[y][x] = false; //(y,x) 기준으로 모든 방향을 가봤음에도 최대가 안나오는 경우 고려하여 다시 방문하지 않았다고 표시
    
    return result = Mars[y][x] + max(max(temp1, temp2), temp3);
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Mars[i][j];
            cache[0][i][j] = cache[1][i][j] = cache[2][i][j] = MININF; //초기화, memset 불가능
        }
    }
    
    memset(visited, false, sizeof(visited));
    cout << maxSum(0, 0, 0) << endl;
    return 0;
}
