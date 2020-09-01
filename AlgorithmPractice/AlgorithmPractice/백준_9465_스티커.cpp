//
//  백준_9465_스티커.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/01.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "start" << endl;
    
    cin >> T;
    
    while(T > 0) {
        cin >> n;
        vector<vector<int>> board(2, vector<int>(n, 0));
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];
        dp[0][1] = dp[1][0] + board[0][1];
        dp[1][1] = dp[0][0] + board[1][1];
        
        for(int j = 2; j < n; j++) {
            for(int i = 0; i < 2; i++) {
                if(i == 0)
                    dp[i][j] = max(dp[1][j-2] + board[i][j], dp[1][j-1] + board[i][j]);
                else
                    dp[i][j] = max(dp[0][j-2] + board[i][j], dp[0][j-1] + board[i][j]);
            }
        }
        
        int answer = max(dp[0][n-1], dp[1][n-1]);
        
        cout << answer << endl;
        
        board.clear();
        dp.clear();
        T--;
    }
    
    
    return 0;
}

