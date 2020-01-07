#include <iostream>
#include <algorithm>
using namespace std;

int cache[1000];

int main() {
    cout << "start" << endl;
    int n;
    cin >> n;
    
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    
    for(int i = 4; i <= n; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % 10007;
    }
    
    cout << cache[n] << endl;
    
    return 0;
}
