#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int cache[MAX];

int main() {
    cout << "start" << endl;
    int n;
    cin >> n;
    
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % 10007;
    }
    
    cout << cache[n] << endl;
    return 0;
}
