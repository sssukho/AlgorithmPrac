#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 16

int N; //상담할 수 있는 기간ㄴ
int dp[MAX];
int t[MAX];
int p[MAX];

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        int T, P;
        cin >> T >> P;
        t[i] = T;
        p[i] = P;
        dp[i] = p[i];
    }
    
    //dp[n] = n일때까지 얻은 수익
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(i-j >= t[j]) {
                dp[i] = max(p[i]+dp[j], dp[i]);
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 1; i <= N; i++) {
        if(i + t[i] <= N + 1) {
            if(ans < dp[i]) {
                ans = dp[i];
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
