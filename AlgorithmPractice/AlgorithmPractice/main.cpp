//어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고
//나머지 논문이 h번 이하 인용되었다면 h가 이 과학자의 H-Index입니다.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    if(a > b)
        return true;
    return false;
}

int solution(vector<int> citations) {
    int answer = 0;
    int n = (int)citations.size();
    
    sort(citations.begin(), citations.end(), compare);
    
    for(int i = 0; i < n; i++) {
        if(i >= citations[i])
            break;
        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> c;
    c.push_back(3);
    c.push_back(0);
    c.push_back(6);
    c.push_back(1);
    c.push_back(5);
    
    cout << solution(c) << endl;
    
    return 0;
}
