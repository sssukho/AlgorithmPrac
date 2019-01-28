#include <iostream>
#include <vector>

using namespace std;

int d[101][100001];

int main() {
    cout << "start" << endl;
    int n, k;
    cin >> n >> k;
    vector<int> w(n+1);
    vector<int> v(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) { //n은 물품 개수. 즉, i는 물품의 개수
        for(int j = 1; j <= k; j++) { //k가 버틸수 있는 무게. 즉, j는 버틸 수 있는 무게를 의미.
            if(w[i] > j) {
                d[i][j] = d[i-1][j];
            }
            else {
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            }
        }
    }
    
    cout << d[n][k] << "\n";
    
    return 0;
}
