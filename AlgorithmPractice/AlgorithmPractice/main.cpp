#include <iostream>
#include <string>
using namespace std;

struct pos {
    int y;
    int x;
};

pos king;
pos stone;

string order;
string kingStart;
string stoneStart;
int N;

int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dx[8] = {0 , 0, 1, -1, 1, 1, -1, -1};

bool check(int y, int x) {
    if(y >= 0 && y < 8 && x >= 0 && x < 8)
        return true;
    return false;
}

void move(int dir) {
    int kingY = king.y;
    int kingX = king.x;
    int stoneY = stone.y;
    int stoneX = stone.x;
    
    int my = kingY + dy[dir];
    int mx = kingX + dx[dir];
    
    if(check(my, mx)) {
        //왕이 가는 경로에 돌이 있는 경우
        if(my == stoneY && mx == stoneX) {
            //돌의 경로도 체크
            if(check(stoneY + dy[dir], stoneX + dx[dir])) {
                stone.y = stoneY + dy[dir];
                stone.x = stoneX + dx[dir];
                king.y = my;
                king.x = mx;
            }
            return;
        }
        
        //왕이 가는 경로에 돌이 없는 경우
        king.y = my;
        king.x = mx;
    }
}

void simulation(string input) {
    if(input == "R") {
        move(2);
    }
    
    else if(input == "L") {
        move(3);
    }
    
    else if(input == "B") {
        move(1);
    }
    
    else if(input == "T") {
        move(0);
    }
    
    else if(input == "RT") {
        move(4);
    }
    
    else if(input == "LT") {
        move(6);
    }
    
    else if(input == "RB") {
        move(5);
    }
    
    else if(input == "LB") {
        move(7);
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> kingStart;
    cin >> stoneStart;
    cin >> N;
    
    //(y,x)
    king = {kingStart[1]-'0'-1, kingStart[0]-'A'};
    stone = {stoneStart[1]-'0'-1, stoneStart[0]-'A'};
    
    for(int i = 0; i < N; i++) {
        cin >> order;
        simulation(order);
    }
    
    char kingX = king.x+'A';
    char stoneX = stone.x+'A';
    int kingY = king.y+1;
    int stoneY = stone.y+1;
    
    cout << kingX << kingY << endl;
    cout << stoneX << stoneY << endl;
    
    return 0;
}
