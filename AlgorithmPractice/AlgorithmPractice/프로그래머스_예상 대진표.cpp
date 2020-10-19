//
//  프로그래머스_예상 대진표.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/20.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int divide(int a, int b, int cnt) {
    if(abs(a-b) == 1) {
        return cnt;
    }
    else {
        if(a % 2 == 1)
            a += 1;
        if(b % 2 == 1)
            b += 1;
        return divide(a/2, b/2, cnt+1);
    }
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    //    answer = divide(a, b, 1);
    
    while(a != b) {
        a = (a+1) / 2;
        b = (b+1) / 2;
        answer++;
    }
    
    return answer;
}

int main() {
    cout << solution(8, 4, 7) << endl;
    
    return 0;
}


