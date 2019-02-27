#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long T[1000001];

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // 입국심사대, 상근이의 친구들
    long long max = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> T[i];
        if(max < T[i])
            max = T[i];
    }

    //가장 오래 걸리는 시간이 가장 시간이 오래걸리는 심사대에서 모든 사람들이 심사를 받는 경우이기 때문.
    long long left = 1, right = max * M;
    long long result = max * M;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;
        for(int i = 0; i < N; i++) {
            total += mid / T[i];
        }

        if(total < M) {
            left = mid + 1;
        }
        else {
            if(result > mid)
                result = mid;
            right = mid - 1;
        }
    }
    cout << result << endl;
    return 0;
}
