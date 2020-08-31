//
//  백준_2294_동전2.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/08/31.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k; //동전 종류, 목표값
vector<int> coins;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "start" << endl;
    cin >> n >> k;
    
    coins.resize(n+1);
    
    for(int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        coins[i] = input;
    }
    
    dp.resize(k+1, 99999);
    
    sort(coins.begin(), coins.end());
    
    // 주어진 동전을 만들 수 있는 최소 방법은 1가지다. => 초기화
    for(int i = 1; i < coins.size(); i++) {
        dp[coins[i]] = 1;
    }
    
    for(int i = 1; i < coins.size(); i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    
    if(dp[k] == 99999)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
    
    
    
    return 0;
}

