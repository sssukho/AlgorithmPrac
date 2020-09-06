//
//  프로그래머스_디스크 컨트롤러_level3_힙.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/06.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 작업소요 시간 기준으로 내림차순 정렬
struct comp {
    bool operator()(vector<int> &a, vector<int> &b)  {
        return a[1] > b[1];
    }
};

// [작업이 요청되는 시점, 작업의 소요시간]
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end()); // 작업 요청 시점으로 오름차순 정렬
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    
    int idx = 0; // jobs 백터의 인덱스
    int second = 0; // 현재 처리중인 작업이 끝나는 시간
    
    while(idx < jobs.size() || !pq.empty()) {
        // second 시간 안에 도착한 jobs가 있다면
        if(idx < jobs.size() && jobs[idx][0] <= second) {
            pq.push(jobs[idx++]);
            continue;
        }
        
        // 남아있는 jobs가 없고 pq에 기다리는 작업들이 있다면
        if(!pq.empty()) {
            // 작업이 끝나는 시간 계산
            second += pq.top()[1];
            // 작업 시간 계산
            answer = answer + (second - pq.top()[0]);
            pq.pop();
        }
        
        // pq가 비어있고, second 안에 들어온 작업 요청이 없다면 바로 다음 작업시간으로 넘긴다.
        else
            second = jobs[idx][0];
    }
    return answer / jobs.size();
}
