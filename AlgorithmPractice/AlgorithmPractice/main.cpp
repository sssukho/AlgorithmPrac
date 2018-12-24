//DP
//https://programmers.co.kr/learn/courses/30/lessons/43104

/*
 그림에서 타일에 적힌 수는 각 타일의 한 변의 길이를 나타낸다. 타일 장식물을 구성하는 정사각형 타일 한 변의 길이를 안쪽 타일부터 시작하여 차례로 적으면 다음과 같다.
 [1, 1, 2, 3, 5, 8, .]
 지수는 문득 이러한 타일들로 구성되는 큰 직사각형의 둘레가 궁금해졌다. 예를 들어, 처음 다섯 개의 타일이 구성하는 직사각형(위에서 빨간색으로 표시한 직사각형)의 둘레는 26이다.
 
 타일의 개수 N이 주어질 때, N개의 타일로 구성된 직사각형의 둘레를 return 하도록 solution 함수를 작성하시오.
 
 N은 1 이상 80 이하의 자연수
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int cache[81];

long long solution(int N) {
    cache[1] = 4;
    cache[2] = 6;
    
    if(N == 1) return cache[N];
    if(N == 2) return cache[N];
    
    for(int i = 3; i < N+1; i++) {
        cache[i] = cache[i-2] + cache[i-1];
    }
    
    return cache[N];
}

int main() {
    
    cout << solution(5) << endl;
    cout << "-------------------------" << endl;
    cout << solution(6) << endl;
    
    return 0;
}

//long long 은 일반 int 형보다 더 큰 범위의 숫자를 다룰 수 있음.
