#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int east[2] = {0, 1}; //y,x
int west[2] = {0, -1};
int south[2] = {1, 0};
int north[2] = {-1, 0};

int A, B; //가로 세로
int N, M; //로봇 개수, 명령 개수

int map[102][102];
vector<pair<pair<int, int>, char>> robot_position; //로봇들의 초기 위치(y,x), 상태
queue<pair<int, pair<char,int>>> order;//로봇 번호, 명령 종류, 해당 명령 반복 횟수
pair<int, int> direction;

void setDirection(int robotNum, char dir, char left_right) {
    if(left_right == 'l') {
        if(dir == 'E') {
            robot_position[robotNum].second = 'N';
        }
        else if(dir == 'W') {
            robot_position[robotNum].second = 'S';
        }
        else if(dir == 'S') {
            robot_position[robotNum].second = 'E';
        }
        else if(dir == 'N') {
            robot_position[robotNum].second = 'W';
        }
    }
    
    else {
        if(dir == 'E') {
            robot_position[robotNum].second = 'S';
        }
        else if(dir == 'W') {
            robot_position[robotNum].second = 'N';
        }
        else if(dir == 'S') {
            robot_position[robotNum].second = 'W';
        }
        else if(dir == 'N') {
            robot_position[robotNum].second = 'E';
        }
    }
    
}

pair<int, int> moveDirection(int y, int x, char dir) {
    int my = 0, mx = 0;
    if(dir == 'E') {
        my = y + east[0];
        mx = x + east[1];
    }
    else if(dir == 'W') {
        my = y + west[0];
        mx = x + west[1];
    }
    else if(dir == 'S') {
        my = y + south[0];
        mx = x + south[1];
    }
    else if(dir == 'N') {
        my = y + north[0];
        mx = x + north[1];
    }
    return make_pair(my, mx);
}

void simulation() {
    while(!order.empty()) {
        int robotNum = order.front().first;
        char ord = order.front().second.first;
        int repeatNum = order.front().second.second;
        order.pop();
        
        for(int i = 0; i < repeatNum; i++) {
            int y = robot_position[robotNum-1].first.first;
            int x = robot_position[robotNum-1].first.second;
            int my = 0;
            int mx = 0;
            
            if(ord == 'F') {
                cout << "----------------" << endl;
                for(int i = 0; i < B; i++) {
                    for(int j = 0; j < A; j++) {
                        cout << map[i][j];
                    }
                    cout << endl;
                }
                direction = moveDirection(y, x, robot_position[robotNum-1].second);
                my = direction.first;
                mx = direction.second;
                
                if(my < 0 || my >= B || mx < 0 || mx >= A) {
                    cout << "Robot " << robotNum << " crashes into the wall\n";
                    return;
                }
                
                else if(map[my][mx] != 0) {
                    cout << "Robot " << robotNum << " crashes into robot " << map[my][mx] << "\n";
                    return;
                }
                
                else if(my >= 0 && my < B && mx >= 0 && mx < A) {
                    map[y][x] = 0;
                    robot_position[robotNum-1].first.first = my;
                    robot_position[robotNum-1].first.second = mx;
                    map[my][mx] = robotNum;
                }
            }
            else if(ord == 'L') {
                setDirection(robotNum-1, robot_position[robotNum-1].second, 'l');
            }
            else if(ord == 'R') {
                setDirection(robotNum-1, robot_position[robotNum-1].second, 'r');
            }
        }
    }
    cout << "OK" << endl;
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> A >> B;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        int x, y;
        char s;
        cin >> x >> y >> s;
        robot_position.push_back(make_pair(make_pair(B-y, x-1), s));
        map[B-y][x-1] = i; //로봇의 초기 위치 지정.
    }

    for(int i = 0; i < M; i++) {
        int r, n;
        char k;
        cin >> r >> k >> n;
        order.push(make_pair(r, make_pair(k, n)));
    }
    
    simulation();
    
    return 0;
}
