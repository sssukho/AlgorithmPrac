//
//  프로그래머스_보행자천국_level_3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/09.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    // 마지막 차원은 왼쪽에서 왔는지, 위에서 왔는지 => 왼쪽=0, 1=위쪽
    vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1, vector<long long> (2)));
    
    // 0: 프리한 길
    // 1: 통행 금지
    // 2: 왼쪽에서 오던 차는 오른쪽으로만, 위에서 오던 차는 아래쪽으로만
    
    // 초기화
    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        dp[i][0][1] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1)
            break;
        dp[0][i][0] = 1;
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            // 바로 위 칸이 프리한 길이면
            if(city_map[i-1][j] == 0) {
                // 위에서 온 길의 수 += (위쪽칸에서 왼쪽으로 온 길의 수 + 위쪽칸에서 위쪽으로부터 온 길의 수)
                dp[i][j][1] += (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            }
            // 바로 위 칸이 좌회전 우회전 금지 길이면
            if(city_map[i-1][j] == 2) {
                // 위에서 온 길의 수 += 위쪽칸에서 위쪽으로부터 온 길의 수
                dp[i][j][1] += (dp[i-1][j][1] % MOD);
            }
            // 바로 왼쪽칸이 프리한 길이면
            if(city_map[i][j-1] == 0) {
                // 왼쪽에서 온 길의 수 += 왼쪽칸에서 왼쪽으로부터 온 길의 수 + 윈쪽칸에서 위쪽으로부터 온 길의 수)
                dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
            }
            // 바로 왼쪽칸이 좌회전 우회전 금지 길이면
            if(city_map[i][j-1] == 2) {
                // 왼쪽에서 온 길의 수 += 왼쪽칸에서 윈쪽으로부터 온 길의 수
                dp[i][j][0] += (dp[i][j-1][0] % MOD);
            }
        }
    }
    
    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    
    return answer;
}
