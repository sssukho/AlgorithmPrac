#include <iostream>
#include <vector>
using namespace std;

int map[101][101];
int N, x, y, d, g;
vector<int> directions;

int getDir(int dir) {
    if(dir == 0)
        return 1;
    else if(dir == 1)
        return 2;
    else if(dir == 2)
        return 3;
    else
        return 0;
}

int main() {
    cout << "start" << endl;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        //초기화
        directions.clear();
        //첫 진행 방향 저장
        directions.push_back(d);
        
        //드래곤 커브 그리기
        while(g--) {
            //저장된 방향을 역순으로 꺼냄
            for(int a = (int)directions.size()-1; a>= 0; a--) {
                //이전 방향에서 90도 꺾인 값 저장
                int dir = directions[a];
                directions.push_back(getDir(dir));
            }
        }
        
        //입력된 좌표 저장
        map[y][x] = 1;
        //나머지 좌표를 그림
        for(int j = 0; j < (int)directions.size(); j++) {
            int dir = directions[j];
            if(dir == 0)
                x++;
            else if(dir == 1)
                y--;
            else if(dir == 2)
                x--;
            else
                y++;
            
            map[y][x] = 1;
        }
    }
    
    int result = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
                result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
