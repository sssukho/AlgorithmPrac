#include <iostream>
#include <algorithm>
using namespace std;

int N, K; //종류, 가치의 합
int coin[11];

void solution() {
    
}

//첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) { //N개의 동전 가치
        cin >> coin[i];
        
    }
    
    int sum = 0;
    
    for(int i = N-1; i >= 0; i--) {
        int x;
        x = K / coin[i];
        sum = sum + x;
        K = K%coin[i];
    }
    
    cout << sum << endl;
    
    return 0;
}
