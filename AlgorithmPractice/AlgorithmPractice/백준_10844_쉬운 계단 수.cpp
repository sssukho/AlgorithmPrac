#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000000
int cache[101][10];

int main() {
    cout << "start" << endl;
    int n;
    cin >> n;
    
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        cache[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if (j == 0)
                cache[i][0] = cache[i-1][1];
            else if(j == 9)
                cache[i][9] = cache[i-1][8];
            else
                cache[i][j] = (cache[i-1][j-1] + cache[i-1][j+1]) % MOD;
        }
    }
    for (int i = 1; i < 10; i++)
        sum = (sum + cache[n][i]) % MOD;
    
    cout << sum % MOD << endl;;
    
    return 0;
}
