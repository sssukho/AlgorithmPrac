//
//  백준_2252_줄 세우기.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/21.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M; // 학생들의 번호는 1번부터 N번, M은 키를 비교한 횟수
int a, b; // M개의 줄에는 키를 비교한 두 학생의 번호 A,B가 주어진다.

// 위상 정렬
void topologicalSort(vector<vector<int>> &graph, vector<int> &linkCnt) {
    queue<int> q;
    
    // 초기: 선행 정점을 가지지 않는 정점을 큐에 삽입
    for(int i = 1; i <= N; i++) {
        if(linkCnt[i] == 0) // 해당 정점의 간선의 수가 0이면
            q.push(i);
    }
    
    // 정점의 수만큼 반복
    for(int i = 0; i < N; i++) {
        // 1. 큐에서 정점 출력
        int v = q.front();
        q.pop();
        cout << v << ' ';
        
        // 2. 해당 정점과 연결된 모든 정점에 대해
        for(auto nextV : graph[v]) {
            // 2-1. 간선의 수 감소
            linkCnt[nextV]--;
            
            // 2.2 선행 정점을 가지지 않는 정점을 큐에 삽입
            if(linkCnt[nextV] == 0) { //해당 정점의 간선의 수가 0이면
                q.push(nextV);
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    // 그래프로 표현
    vector<vector<int>> graph(N+1, vector<int>());
    // 각 번호별 연결된 간선 개수
    vector<int> linkCnt(N+1, 0);
    
    for(int i = 0; i < M; i++) {
        // 학생 a가 학생 b의 앞에 서야 한다는 의미.
        cin >> a >> b;
        graph[a].push_back(b);
        linkCnt[b]++;
    }
    
    // 위상 정렬(A B : A가 B앞에 선다. A가 선행)
    topologicalSort(graph, linkCnt);
    
    
    return 0;
}

