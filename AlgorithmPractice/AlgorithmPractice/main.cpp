/*
 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
 
 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
 2. X가 2로 나누어 떨어지면, 2로 나눈다.
 3. 1을 뺀다.
 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
 
 입력
 첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.
 
 출력
 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
 */
 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 1000001

int N;

int cache[MAX];

int solution(int num, int cnt) {
    //base case
    if(num == 1)
        return cnt;
    //N이 3으로 나누어 떨어지면 3으로 나눈다.
    else if(num % 3 == 0)
        solution(num/3, cnt++);
    //N이 2로 나누어 떨어지면 2로 나눈다.
    else if(num % 2 == 0)
        solution(num/2, cnt++);
    //N에서 1을 뺀다.
    else
        solution(num-1, cnt++);
    
    return cnt;
}

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    cin >> N;
    
    cache[1] = 0;
    for(int i = 2; i <= N; i++) {
        cache[i] = cache[i-1] + 1;
        if(i % 3 == 0)
            cache[i] = min(cache[i], cache[i/3]+1);
        else if(i % 2 == 0)
            cache[i] = min(cache[i], cache[i/2]+1);
    }
    
    cout << cache[N] << endl;
    
    return 0;
}
