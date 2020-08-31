//
//  백준_2839_설탕 배달.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/01.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 999999

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "start" << endl;
    
    int n; // 목표치
    cin >> n;
    vector<int> dp(n+1, MAX); // 최소 개수 메모이제이션
    
    dp[3] = 1;
    dp[5] = 1;
    
    // Bottom-up
    for(int i = 6; i <= n; i++) {
        dp[i] = min(dp[i-5]+1, dp[i-3]+1);
    }
    
    if(dp[n] >= MAX)
        cout << "-1\n";
    
    else
        cout << dp[n] << '\n';
    
    return 0;
}

