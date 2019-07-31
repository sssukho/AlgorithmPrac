#include <iostream>
#define MAX 90
using namespace std;
int N;
long long int dp[MAX];

int main() {
    cout << "start" << endl;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
