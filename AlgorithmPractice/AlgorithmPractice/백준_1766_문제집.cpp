//
//  백준_1766_문제집.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/22.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; // 문제의 수, 문제에 대한 정보의 개수

// 1. N개의 문제는 모두 풀어야 한다.
// 2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
// 3. 가능하면 쉬운 문제부터 풀어야 한다.

void topologicalSort(vector<vector<int>> &problem, vector<int> &edgeCnt) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // 문제 번호를 넣어준다.
    for(int i = 1; i <= N; i++) {
        if(edgeCnt[i] == 0) {
            pq.push(i);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        int p = pq.top();
        pq.pop();
        
        cout << p << ' ';
        
        for(auto nextP : problem[p]) {
            // nextP 다음에 있던 문제들
            edgeCnt[nextP]--;
            
            if(edgeCnt[nextP] == 0)
                pq.push(nextP);
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<vector<int>> problem(N+1, vector<int>());
    vector<int> edgeCnt(N+1);
    
    int a, b;
    
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        problem[a].push_back(b);
        edgeCnt[b]++; // 문제당 진입차수 카운트 올려줌
    }
    
    topologicalSort(problem, edgeCnt);
    
    
    return 0;
}
