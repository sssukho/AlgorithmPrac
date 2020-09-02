//
//  프로그래머스_정수삼각형_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/02.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
    
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0)
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if(j == i)
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
            
            if(i == triangle.size()-1)
                answer = max(answer, dp[i][j]);
        }
    }
    
    return answer;
}

int main() {
    vector<vector<int>> t;
    t.resize(5);
    
    t[0].push_back(7);
    
    t[1].push_back(3);
    t[1].push_back(8);
    
    t[2].push_back(8);
    t[2].push_back(1);
    t[2].push_back(0);
    
    t[3].push_back(2);
    t[3].push_back(7);
    t[3].push_back(4);
    t[3].push_back(4);
    
    t[4].push_back(4);
    t[4].push_back(5);
    t[4].push_back(2);
    t[4].push_back(6);
    t[4].push_back(5);
    
    cout << solution(t) << endl;
    
    return 0;
}






/** 실패한 코드*****************
 * 실패 이유 :
 *
 *
 ****************************/
/*
int solution(vector<vector<int>> triangle) {
    
    vector<vector<int>> dp = triangle;
    
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[dp[i].size()-1].size(); j++) {
            if(i == dp.size()-1 ) {
                dp[i][j] = triangle[i][j];
            }
            else {
                dp[i][j] = -1;
            }
        }
    }
    
    for(int i = (int)dp.size()-2; i >= 0; i--) {
        for(int j = (int)dp[dp[i].size()-1].size(); j >= 0; j--) {
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    return dp[0][0];
}
*/
