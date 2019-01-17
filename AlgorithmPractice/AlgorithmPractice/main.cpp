#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, n; //테스트 케이스 수, 편의점 수
int sx, sy; //상근이네 집(출발점 좌표)
int ex ,ey; //락페 좌표(도착점 좌표)
int store[100][2], visited[101]; //편의점의 좌표, 방문한 노드 체크
bool check; //종료 조건 주기 위한 bool 변수

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> T; //테스트케이스 수
    for(int t = 0; t < T; t++) {
        cin >> n; //편의점 수
        cin >> sx >> sy; //출발점 좌표(상근이네 집)
        
        for(int i = 0; i < n; i++) {
            cin >> store[i][0] >> store[i][1];
        }
        
        cin >> ex >> ey; //락페 좌표
        int r = abs(sx-ex) + abs(sy-ey); //출발점에서 도착점 까지의 맨해튼 거리
        check = false; //종료 조건 줄라고
        
        if(r <= 1000) //출발점에서 도착점 까지의 거리가 맥주 개수(20) 으로 무조건 갈 수 있는 거리면 그냥 종료.
            check = true;
        else {
            queue<pair<int, int>> q;
            q.push(make_pair(sx, sy));
            while(!q.empty()) {
                int qn = q.size();
                for(int k = 0; k < qn; k++) {
                    int nx = q.front().first;
                    int ny = q.front().second;
                    q.pop();
                    
                    if(abs(nx-ex) + abs(ny-ey) <= 1000) { //현재 편의점(맥주를 충전할 수 있는 위치)과 락페(도착지)와의 맨해튼 거리가 1000m 이내면
                        check = true;
                        break;
                    }
                    for(int i = 0; i < n; i++) {
                        //집과 펜타포트 위치 사이 안에 있지 않고 밖에 있는 편의점도 가능하게 했더니 pass
                        //원래 abs(mx-nx) + abs(my-ny) <= r로 설정했었는데 fail
                        int mx = store[i][0], my = store[i][1];
                        if(!visited[i] && abs(mx-nx) + abs(my-ny) <= 1000) {
                            q.push(make_pair(mx, my));
                            visited[i] = true;
                        }
                    }
                }
            }
            
            memset(visited, false, sizeof(visited));
            while(!q.empty())
                q.pop();
        }
        if(check)
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    
    return 0;
}
