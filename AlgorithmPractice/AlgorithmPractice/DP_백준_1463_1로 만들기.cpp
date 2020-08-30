//
//  DP_백준_1463_1로 만들기.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/08/30.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;

int solution(int n) {
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        
        if(i%3 == 0) {
            dp[i] = min(dp[i/3]+1, dp[i]);
        }
        if(i%2 == 0) {
            dp[i] = min(dp[i/2]+1, dp[i]);
        }
    }
    
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "start" << endl;
    
    int n;
    cin >> n;
    
    dp.resize(n+1);
    
    cout << solution(n) << '\n';
    
    return 0;
}

