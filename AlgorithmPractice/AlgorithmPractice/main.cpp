#include <iostream>

using namespace std;

#define MAX 101

int N;
int numbers[MAX];
//long long cache[N][M] N번까지의 수의 식을 세웠을 때 나오는 값 M에 대한 경우의 수
long long cache[MAX][21];

long long solve(int depth, int sum) {
    if(sum < 0 || sum > 20)
        return 0;
    
    if(depth == N-2) {
        if(sum == numbers[N-1])
            return 1;
        else
            return 0;
    }
    
    if(cache[depth+1][sum] > 0)
        return cache[depth+1][sum];
    
    cache[depth+1][sum] = cache[depth][sum] + solve(depth+1, sum+numbers[depth+1]);
    cache[depth+1][sum] = cache[depth][sum] + solve(depth+1, sum-numbers[depth+1]);
    
    return cache[depth+1][sum];
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> numbers[i];
    
    cout << solve(0, numbers[0]) << endl;
    
    return 0;
}
