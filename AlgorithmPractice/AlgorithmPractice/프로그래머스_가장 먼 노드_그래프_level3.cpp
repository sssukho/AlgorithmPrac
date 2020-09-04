//
//  프로그래머스_가장 먼 노드_그래프_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/04.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> conInfo(n+1);
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, 0);
    queue<int> q;
    
    for(int i = 0; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];
        
        conInfo[start].push_back(end);
        conInfo[end].push_back(start);
    }
    
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int start = q.front();
        q.pop();
        
        for(int i = 0; i < conInfo[start].size(); i++) {
            int connectedNode = conInfo[start][i];
            if(visited[connectedNode] == false) {
                q.push(connectedNode);
                visited[connectedNode] = true;
                distance[connectedNode] = distance[start] + 1;
            }
        }
    }
    
    
    sort(distance.begin(), distance.end(), comp);
    
    for(auto d : distance) {
        if(d == distance[0])
            answer++;
    }
    return answer;
}
