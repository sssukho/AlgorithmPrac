#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int n;
int dp[MAX];
int wine[MAX];

int maxCount() {
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    
    if(n == 1)
        return dp[1];
    else if(n == 2)
        return dp[2];
    else {
        for(int i = 3; i <= n; i++) {
            dp[i] = max(dp[i-1], max(dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]));
        }
        return dp[n];
    }
}

int main() {
    cout << "start" << endl;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    cout << maxCount() << endl;
    return 0;
}
