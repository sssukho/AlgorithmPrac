//
//  NHN Pre-Test 기출.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/05.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int n;
int area;
int cnt = 1;

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < n && mx >= 0 && mx < n) {
            if(!visited[my][mx] && board[my][mx] == 1) {
                cnt++;
                dfs(my, mx);
            }
        }
    }
}

vector<int> solution() {
    vector<int> answer;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && board[i][j] == 1) {
                area++;
                dfs(i, j);
                answer.push_back(cnt);
                cnt = 1;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    cout << "start" << endl;
    
    cin >> n;
    
    board.resize(n+1, vector<int> (n));
    visited.resize(n+1, vector<bool> (n, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    vector<int> ans = solution();
    
    cout << area << endl;
    
    for(auto x : ans) {
        cout << x << ' ';
    }
    
    return 0;
}

