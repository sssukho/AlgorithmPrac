#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int T;
int n;
int map[2][MAX];
int dp[2][MAX]; //최대값 저장

int main() {
    cout << "start" << endl;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        cin >> n;
        
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = map[0][1] + dp[1][0];
        dp[1][1] = map[1][1] + dp[0][0];
        
        for(int i = 2; i < n; i++) {
            dp[0][i] = map[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = map[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
    
    
    
    return 0;
}
