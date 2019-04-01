//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//#define MAX 501
//struct pos{
//    int y1,y2,y3,y4;
//    int x1,x2,x3,x4;
//};
//
//int N, M; //세로, 가로
//int board[MAX][MAX];
//
//int dy[4] = { 1, -1, 0, 0};
//int dx[4] = { 0, 0, 1, -1};
//
//int ans = -98776;
//vector<int> comb;
//
//bool isTetromino(pos input) {
//    int y1 = input.y1, y2 = input.y2, y3 = input.y3, y4 = input.y4;
//    int x1 = input.x1, x2 = input.x2, x3 = input.x3, x4 = input.x4;
//
//    //에메랄드색
//    if(y1 == y2 && y2 == y3 && y3 == y4) {
//        if(x1-x2 == -1 && x2-x3 == -1 && x3-x4 == -1)
//            return true;
//    }
//    //에메랄드 색 회전
//    if(x1 == x2 && x2 == x3 && x3 == x4) {
//        if(y1-y2 == -1 && y2-y3 == -1 && y3-y4 == -1)
//            return true;
//    }
//    //노랑색
//    if(y1==y2 && y3==y4 && y1-y3==-1) {
//        if(x1-x2 == -1 && x3-x4 == -1 && x1==x3)
//            return true;
//    }
//
//    //주황
//    if(y1-y2 == -1 && y2-y3 == -1 && y3 == y4) {
//        if(x1 == x2 && x2 == x3 && x3-x4 == -1)
//            return true;
//    }
//
//    //주황 회전1
//    if(y1-y4 == -1 && y4 == y3 && y3 == y2) {
//        if(x1 == x4 && x4-x3 == 1 && x3-x2 == 1)
//            return true;
//    }
//
//    //주황 회전2
//    if(y1==y2 && y2-y3 == -1 && y3-y4 == -1) {
//        if(x1-x2 == -1 && x2==x3 && x3==x4)
//            return true;
//    }
//
//    //주황 회전3
//    if(y1==y2 && y2==y3 && y1-y4==-1) {
//        if(x1==x4 && x1-x2==-1 && x2-x3==-1)
//            return true;
//    }
//
//    //주황 대칭1
//    if(y1==y2 && y1-y3 == -1 && y3-y4 == -1) {
//        if(x1-x2==-1 && x1==x3 && x3==x4)
//            return true;
//    }
//
//    //주황 대칭2
//    if(y1-y2==-1 && y2-y4==-1 && y3==y4) {
//        if(x1==x2 && x2==x4 && x3-x4==-1)
//            return true;
//    }
//
//    //주황 대칭3
//    if(y1-y2==-1 && y2==y3 && y3==y4) {
//        if(x1==x2 && x2-x3==-1 && x3-x4==-1)
//            return true;
//    }
//
//    //주황 대칭4
//    if(y1==y2 && y2==y3 && y3-y4==-1) {
//        if(x1-x2==-1 && x2-x3==-1 && x3==x4)
//            return true;
//    }
//
//    //초록색
//    if(y1-y2==-1 && y2==y3 && y3-y4==-1) {
//        if(x1==x2 && x2-x3 == -1 && x3==x4)
//            return true;
//    }
//
//    //초록 회전
//    if(y1==y2 && y1-y3 == -1 && y3==y4) {
//        if(x1-x2==-1 && x1==x4 && x3-x4 == -1)
//            return true;
//    }
//
//    //초록 대칭1
//    if(y1-y3==-1 && y2==y3 && y2-y4==-1) {
//        if(x1==x3 && x2-x3==-1 && x2==x4)
//            return true;
//    }
//
//    //초록 대칭2
//    if(y1==y2 && y2-y3==-1 && y3==y4) {
//        if(x1-x2==-1 && x2==x3 && x3-x4==-1)
//            return true;
//    }
//
//    //보라색
//    if(y1-y2==-1 && y2==y3 && y3==y4) {
//        if(x1==x3 && x2-x3 == -1 && x3-x4==-1)
//            return true;
//    }
//
//    //보라 회전1
//    if(y1-y2==-1 && y2==y3 && y2-y4==-1) {
//        if(x1==x2 && x2-x3==-1 && x2==x4)
//            return true;
//    }
//
//    //보라 회전2
//    if(y1==y2 && y2==y3 && y2-y4==-1) {
//        if(x1-x2==-1 && x2-x3==-1 &&x2==x4) {
//            return true;
//        }
//    }
//
//    //보라 회전3
//    if(y1-y3==-1 && y3-y4==-1 && y2==y3) {
//        if(x1==x3 && x3==x4 && x2-x3==-1)
//            return true;
//    }
//
//    return false;
//}
//
//int main() {
//    cout << "start" << endl;
//    cin >> N >> M; //세로 가로
//
//    for(int i = 0; i < N; i++)
//        for(int j = 0; j < M; j++)
//            cin >> board[i][j];
//
//    for(int i = 0; i < 4; i++) {
//        comb.push_back(1);
//    }
//
//    for(int i = 0; i < N*M-4; i++) {
//        comb.push_back(0);
//    }
//
//    //[i/5][i%5]
//    vector<int> idx;
//
//    do {
//        for(int i = 0; i < N*M; i++) {
//            if(comb[i] == 1) {
//                idx.push_back(i);
//            }
//        }
//
//        sort(idx.begin(), idx.end());
//
//        int y1 = idx[0]/M, y2 = idx[1]/M, y3 = idx[2]/M, y4 = idx[3]/M;
//        int x1 = idx[0]%M, x2 = idx[1]%M, x3 = idx[2]%M, x4 = idx[3]%M;
//
//        pos p = { y1, y2, y3, y4, x1, x2, x3, x4 };
//
//        if(isTetromino(p)) {
//            int sum = board[y1][x1] + board[y2][x2] + board[y3][x3] + board[y4][x4];
//            ans = max(ans, sum);
//        }
//
//        idx.clear();
//    }while(prev_permutation(comb.begin(), comb.end()));
//
//
//    cout << ans << endl;
//    return 0;
//}
//////////////조합으로 풀면 시간초과/////////////

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 501

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int N, M;
int cell[MAX][MAX];
bool visited[MAX][MAX];

//전형적인 DFS
int dfs(int y, int x, int cnt) {
    if(cnt == 4)
        return cell[y][x];
    
    int sum = 0;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < N && mx >= 0 && mx < M) {
            if(!visited[my][mx]) {
                visited[my][mx] = true;
                sum = max(sum, cell[y][x] + dfs(my, mx, cnt+1));
                visited[my][mx] = false; //꼭 처리 해줘야 한다.
            }
        }
    }
    return sum;
}

//dfs로 판별할 수 없는 테트로미노
int middleFinger(int y, int x) {
    int result = 0;
    //ㅗ (현재 좌표 ㅡ의 가운데)
    if (y >= 1 && x >= 1 && x < M - 1)
        result = max(result, cell[y][x - 1] + cell[y][x] + cell[y - 1][x] + cell[y][x + 1]);
    
    //ㅏ (현재 좌표 ㅣ의 가운데)
    if (y >= 1 && y < N - 1 && x < M - 1)
        result = max(result, cell[y - 1][x] + cell[y][x] + cell[y][x + 1] + cell[y + 1][x]);
    
    //ㅜ (현재 좌표 ㅡ의 가운데)
    if (y >= 1 && y < N - 1 && x < M - 1)
        result = max(result, cell[y][x - 1] + cell[y][x] + cell[y + 1][x] + cell[y][x + 1]);
    
    //ㅓ (현재 좌표 ㅣ의 가운데)
    if (y >= 1 && y < N - 1 && x >= 1)
        result = max(result, cell[y - 1][x] + cell[y][x] + cell[y][x - 1] + cell[y + 1][x]);
    
    return result;
}

int main() {
    cout << "start" << endl;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> cell[i][j];
    
    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;
            result = max(result, dfs(i, j, 1));
            result = max(result, middleFinger(i, j));
            visited[i][j] = false;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
