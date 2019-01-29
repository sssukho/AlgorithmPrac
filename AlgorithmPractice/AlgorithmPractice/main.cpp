/*
 문제
 N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
 
 N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
 
 입력
 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
 
 출력
 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[15];
int result = 0;

bool promising(int i) {
    for(int j =0; j < i; j++) {
        //새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if(map[j] == map[i] || abs(map[i]-map[j]) == (i-j))
            return false;
    }
    return true;
}

void N_Queen(int i) {
   if(i == N)
       result++;
   else {
       for(int j = 0; j < N; j++) {
           map[i] = j;
           if(promising(i))
               N_Queen(i+1);
       }
   }
}

int main() {
    cout << "start" << endl;
    cin >> N;
    N_Queen(0);
    cout << result << endl;
    return 0;
}
