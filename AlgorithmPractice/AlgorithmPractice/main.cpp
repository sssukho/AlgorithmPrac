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
#include <cstring>
using namespace std;

int n;
bool *arr; //열의 개수 (세로 개수)
bool *d1; //오른쪽 위를 향하는 대각(각 자리의 합) = (2n-1)개
bool *d2; //오른쪽 아래를 향하는 대각 {(n-1) + (행-열) 로 구분}
int result = 0;

void Solution(int y) {
    if(y >= n) result++;
    
    for(int i = 0; i < n; i++) {
        if(arr[i]) continue; //arr[i]가 존재하면 continue;
        if(d1[y+i] || d2[n-1+(y-i)]) continue; //대각선상에 존재하면 continue;
        
        arr[i] = d1[y+i] = d2[n-1 + (y-i)] = true; //체크하고
        Solution(y+1); //아래 행으로 넘어감
        arr[i] = d1[y+i] = d2[n-1+(y-i)] = false; //백트랙킹 조건
    }
}

int main() {
    cout << "start" << endl;
    cin >> n;
    arr = new bool[n];
    d1 = new bool[2*n-1];
    d2 = new bool[2*n-1];
    
    Solution(0);
    cout << result << endl;

}
