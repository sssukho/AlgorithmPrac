//
//  프로그래머스_야근 지수_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/08.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 야근 피로도 += 남은 일의 작업량^2
// n = 퇴근까지 남은 시간
// works = 각 일에 대한 작업량
// 최대값을 줄이는 것이 목표
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(auto w : works)
        pq.push(w);
    
    while(n > 0) {
        int front = pq.top();
        pq.pop();
        
        front--;
        if(front < 0) {
            n--;
            continue;
        }
        
        pq.push(front);
        n--;
    }
    
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}
