#include <iostream>
#include <math.h>
using namespace std;

int cache[12];
int N;
void solution() {
    for(int i = 5; i <= N; i++) {
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    }
}

int main() {
    cout << "start" << endl;
    int T;
    cin >> T;
    
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    cache[4] = 7;
    
    for(int t = 0; t < T; t++) {
        cin >> N;
        solution();
        cout << cache[N] << endl;
    }
    
    return 0;
}
