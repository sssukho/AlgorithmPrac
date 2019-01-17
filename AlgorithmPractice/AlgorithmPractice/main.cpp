/*
 송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에 가려고 한다. 올해는 맥주를 마시면서 걸어가기로 했다. 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 맥주 한 박스에는 맥주가 20개 들어있다. 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다.
 
 상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 따라서, 맥주를 더 구매해야 할 수도 있다. 미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.
 
 편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.
 
 [입력]
 첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)
 
 각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).
 
 다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)
 
 송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)
 
 [출력]
 각 테스트 케이스에 대해서 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 중간에 맥주가 바닥나면 "sad"를 출력한다.
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, n, sx, sy ,ex ,ey, store[100][2], visited[101];
bool check;

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
            visited[i] = false;
        }
        
        cin >> ex >> ey; //락페 좌표
        int r = abs(sx-ex) + abs(sy-ey); //(현재 y좌표 - 락페 y좌표) + 현재 x좌표 - 락페 x좌표)의 절대값끼리 더한것
        check = false; //종료 조건 줄라고
        
        if(r <= 1000)
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
                    
                    
                    if(abs(nx - ex) + abs(ny -ey) <= 1000) {
                        check = true;
                        while(!q.empty())
                            q.pop();
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
