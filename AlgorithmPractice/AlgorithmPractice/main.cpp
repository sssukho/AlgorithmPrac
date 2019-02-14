#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T;
int N, K; //강좌 개수, k개 적절한 순서로 선택
vector<int> numbers;

bool cmp(int a, int b) {
    if(a >= b)
        return true;
    else
        return false;
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        float result = 0.0;
        numbers.clear();
        
        cin >> N >> K; //N은 강좌 개수, 선택 개수
        for(int i = 0; i < N; i++) {
            int input;
            cin >> input;
            numbers.push_back(input);
        }
        
        sort(numbers.begin(), numbers.end(), cmp);
        
        for(int i = K-1; i >= 0; i--) {
            result = (result+numbers[i]) / 2;
        }

        printf("#%d %.6f\n", t+1, result);
    }
    
    
    return 0;
}
