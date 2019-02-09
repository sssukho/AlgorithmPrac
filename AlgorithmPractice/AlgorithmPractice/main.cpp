#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

//상어 구조체
struct fish {
    int y;
    int x;
    int size;
    int eat; //몇 마리 먹었는지
    int time; //이동한 시간
};

int N;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int map[21][21];
bool visited[21][21];

queue<fish> q; // 방문 가능한 위치 - 사이즈가 같거나 0인 곳
vector<fish> v; // 먹을 수 있는 물고기 - 사이즈가 작은 곳

//문제 조건에 맞는 비교연산
bool cmp(fish a, fish b) {
    //가장 짧은 시간
    if(a.time <= b.time) {
        //시간이 같을 경우
        if (a.time == b.time) {
            // y값이 더 작은 순서 (북쪽에 있는 물고기 우선)
            if(a.y <= b.y) {
                // y값이 같다면
                if(a.y == b.y) {
                    // x값이 작은 순서로 정렬
                    if(a.x < b.x) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    fish ex; // 이전 상어의 상태 저장
    
    //입력
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) { //아기상어 - 시작위치
                map[i][j] = 0;
                //초기화
                ex = { i,j,2,0,0 };
            }
        }
    }
    
    int ans = 0; //시간 정보
    while(true) {
        // 물고기를 한번 먹을때마다 다시 초기화
        v.clear(); // 먹을 수 있는 물고기 update, 우선 순위가 다를수도 있고,,, 그러므로 지우기
        memset(visited, false, sizeof(visited)); //방문했던 곳 다시 시작
                                                //잡아 먹은 물고기는 0으로 바꿔줬으니 신경x
        visited[ex.y][ex.x] = true;
        q.push(ex);
        
        while (!q.empty()) { //map의 방문가능 한 모두 방문하기
                             //크기가 작거나, 0인곳(길 혹은 이미 먹은 곳
            int y = q.front().y;
            int x = q.front().x;
            int size = q.front().size;
            int eat = q.front().eat;
            int time = q.front().time;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int my = y + dy[i];
                int mx = x + dx[i];
                if(my >= 0 && my < N && mx >= 0 && mx < N) {
                    if(!visited[my][mx]) {
                        //사이즈가 같은 상어이가너 길(0)인 경우
                        if(map[my][mx] == 0 || map[my][mx] == size) {
                            visited[my][mx] = true;
                            q.push({my, mx, size, eat, time+1});
                        }
                        //작은 상어 - 먹을 수 있음
                        else if(map[my][mx] < size) {
                            visited[my][mx] = true; //방문 표시
                            v.push_back({my, mx, size, eat+1, time+1});
                        }
                    }
                }
            }
        }
        
        //만약 벡터가 비어있다면 잡아 먹을 수 있는 상어 없음
        // map의 모든 곳을 다 확인했으니까!
        if(v.size() == 0)
            break;
        
        // vector v = 먹을 수 있는 물고기들의 리스트
        // 이걸 문제의 조건(cmp)에 따라 정렬한다.
        sort(v.begin(), v.end(), cmp);
        
        // 먹은 상어의 숫자가 현재 사이즈와 같다면 사이즈 증가
        if(v[0].size == v[0].eat) {
            v[0].size++;
            v[0].eat = 0;
        }
        
        //잡아먹은 상어는 map에서 지움
        map[v[0].y][v[0].x] = 0;
        //이동 시간 저장
        ans = ans + v[0].time;
        //시간을 초기화하고 다시 큐에 넣어 이전 과정을 반복
        ex = { v[0].y, v[0].x, v[0].size, v[0].eat, 0 };
    }
    
    cout << ans << endl;
    
    return 0;
}
