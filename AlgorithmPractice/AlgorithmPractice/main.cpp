#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 16

int N;
int arr[MAX];
int cnt = 0;

void dfs(int n) {
    
    if(n == N+1){
        cnt++;
        return;
    }
    
    for(int i=1; i<N+1; i++){
        bool flag = true;
        int temp[MAX];
        //memcpy(temp, arr, sizeof(arr));
        for(int j = 1; j<n; j++){
            if(arr[j]==i || abs(n-j) == abs(arr[j] - i)){
                flag = false;
            }
        }
        if(flag == true){
            arr[n] = i;
            dfs(n+1);
        }
        //memcpy(arr, temp, sizeof(temp)); //
    }
    
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    dfs(1);
    cout << cnt << endl;
    return 0;
}
