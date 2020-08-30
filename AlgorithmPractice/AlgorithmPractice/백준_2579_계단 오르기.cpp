//
//  백준_2579_계단 오르기.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/08/30.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int stairCnt;
vector<int> stairs;
vector<int> dp;

/**
 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
 3. 마지막 도착 계단은 반드시 밟아야 한다.
 **/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "start" << endl;
    
    cin >> stairCnt;
    dp.resize(stairCnt);
    
    int num;
    for(int i = 0; i < stairCnt; i++) {
        cin >> num;
        stairs.push_back(num);
    }
    
    dp[0] = stairs[0];
    dp[1] = max(stairs[1], stairs[0]+stairs[1]);
    dp[2] = max(stairs[1]+stairs[2], stairs[0]+stairs[2]);
    
    for(int i = 3; i < stairCnt; i++) {
        dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    }
    
    cout << dp[stairCnt-1] << endl;
    return 0;
}

