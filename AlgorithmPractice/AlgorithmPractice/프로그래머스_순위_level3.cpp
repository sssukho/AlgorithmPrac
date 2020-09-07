//
//  프로그래머스_순위_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/07.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 선수의 수, 경기 결과 = 2차원 배열
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    
    // 승리한 경우 추가
    for(auto r : results) {
        int winner = r[0];
        int loser = r[1];
        graph[winner][loser] = true;
    }
    
    // 플로이드 와샬 알고리즘 적용
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                //
                if(graph[j][i] && graph[i][k])
                    graph[j][k] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int winCount = 0;
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] || graph[j][i]) winCount++;
        }
        if (winCount == n-1)
            answer++;
    }
    
    return answer;
}
