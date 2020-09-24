//
//  프로그래머스_멀리뛰기_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/25.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> dp(n+1);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    
    for(int i = 5; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    answer = dp[n];
    
    return answer;
}
