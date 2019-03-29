#include <iostream>
#include <vector>
using namespace std;
#define MAX 21

struct Dice {
    int up;
    int down;
    int right;
    int left;
    int front;
    int rear;
    int y;
    int x;
};

int map[MAX][MAX];
int dy[4] = {0, 0, -1, 1}; //1동쪽, 2서쪽, 3북, 4남
int dx[4] = {1, -1, 0, 0};

int N, M; //세로, 가로
int X, Y, K;
vector<int> order;

Dice dice;

void setDice(int dir) {
    int up = dice.up;
    int down = dice.down;
    int right = dice.right;
    int left = dice.left;
    int front = dice.front;
    int rear = dice.rear;
    //동쪽으로 굴리면
    if(dir == 0) {
        dice.down = right;
        dice.up = left;
        dice.right = up;
        dice.left = down;
        dice.front = front;
        dice.rear = rear;
    }
    //왼쪽으로 굴리면
    else if(dir == 1) {
        dice.down = left;
        dice.up = right;
        dice.right = down;
        dice.left = up;
        dice.front = front;
        dice.rear = rear;
    }
    //북쪽으로 굴리면
    else if(dir == 2) {
        dice.down = rear;
        dice.up = front;
        dice.right = right;
        dice.left = left;
        dice.front = down;
        dice.rear = up;
    }
    //남쪽으로 굴리면
    else {
        dice.down = front;
        dice.up = rear;
        dice.right = right;
        dice.left = left;
        dice.front = up;
        dice.rear = down;
    }
}

void simulation() {
    dice = { 0, 0, 0, 0, 0, 0, Y, X };
    
    for(int k = 0; k < K; k++) {
        int dir = order[k]-1;
        int my = dice.y + dy[dir];
        int mx = dice.x + dx[dir];
        
        if(my < 0 || my >= N || mx < 0 || mx >= M)
            continue;
        
        if(map[my][mx] == 0) {
            setDice(dir);
            map[my][mx] = dice.down;
            dice.y = my;
            dice.x = mx;
            cout << dice.up << endl;
        }
        
        else {
            setDice(dir);
            dice.down = map[my][mx];
            map[my][mx] = 0;
            dice.y = my;
            dice.x = mx;
            cout << dice.up << endl;
        }
    }
}

int main() {
    cin >> N >> M >> Y >> X >> K; //세로, 가로, y(세로), x(가로), 명령 개수
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    map[Y][X] = 0;
    
    for(int i = 0; i < K; i++) {
        int input;
        cin >> input;
        order.push_back(input);
    }
    
    simulation();
    
    return 0;
}
