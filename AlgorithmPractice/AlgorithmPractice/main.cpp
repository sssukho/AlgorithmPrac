#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

struct pos {
    int x1, y1, x2, y2;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool visited[MAX][MAX];
int M, N, K; //세로, 가로, 직사각형 개수
vector<pos> recPos;
vector<int> result;
queue<pair<int, int>> q;
int cellCount = 0;
int areaCount = 0;

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >=1 && my <= M && mx >= 1 && mx <= N) {
            if(!visited[my][mx]) {
                cellCount++;
                dfs(my, mx);
            }
        }
    }
}

void makeArea() {
    for(int r = 0; r < recPos.size(); r++) {
        int y1 = recPos[r].y1;
        int x1 = recPos[r].x1;
        int y2 = recPos[r].y2;
        int x2 = recPos[r].x2;
        
        for(int i = y1; i <= y2; i++)
            for(int j = x1; j <= x2; j++)
                visited[i][j] = true;
    }
}

int main() {
    cout << "start" << endl;
    cin >> M >> N >> K;
    for(int k = 0; k < K; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        recPos.push_back({x1+1, y1+1, x2, y2});
    }
    
    makeArea();
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(!visited[i][j]) {
                cellCount = 1;
                dfs(i, j);
                areaCount++;
                result.push_back(cellCount);
            }
        }
    }
    
    
    sort(result.begin(), result.end());
    
    cout << areaCount << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
