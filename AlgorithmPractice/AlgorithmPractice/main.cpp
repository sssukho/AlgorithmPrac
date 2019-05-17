/*
 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
 3. 그렇지 않으면 J를 인쇄합니다.
 */
//a, b, c, d
//2, 1, 3, 2

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < (int)priorities.size(); i++) {
        //처음 대기목록 순서, 중요도
        q.push(make_pair(i, priorities[i]));
        //우선순위 큐에 작업 중요도
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        //출력순서가 왔을 때
        if(q.front().second == pq.top()) {
            //처음 대기 목록 순서와 문제에서 요청된 문서번호 같을 때
            if(q.front().first == location)
                return answer + 1;
            else {
                //출력 후 작업 큐와 우선순위 큐에서 문서를 하나씩 pop
                answer++;
                q.pop();
                pq.pop();
            }
        }
        else {
            //출력순서가 아니므로 front에 있는 값을 큐의 맨뒤로 이동
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}

int main() {
    vector<int> pri1 = {2, 1, 3, 2};
    vector<int> pri2 = {1, 1, 9, 1, 1, 1};
    
    cout << solution(pri1, 2) << endl;
    cout << solution(pri2, 5) << endl;
    
    return 0;
}
