#include <iostream>
using namespace std;

int N, S;
int val[20];
int cnt, currentSum;

//current는 노드 번호를 말하는 것
void dfs(int current) {
    if(current == N)
        return;
    
    // 현재까지의 합이 S면 결과 + 1
    if(currentSum + val[current] == S)
        cnt++;
    
    // 이번 원소를 포함시키지 않고 시도
    dfs(current + 1);
    
    // 이번 원소를 포함시키고 시도
    // currentSum이 전역변수니까
    currentSum = currentSum + val[current];
    dfs(current+1);
    
    // 마지막에 다시 이번 원소를 빼줘야 함
    currentSum = currentSum - val[current];
}

int main() {
    cout << "start" << endl;
    cin >> N >> S;
    
    for(int i = 0; i < N; i++)
        cin >> val[i];
    
    dfs(0);
    cout << cnt << endl;
    
    return 0;
}
