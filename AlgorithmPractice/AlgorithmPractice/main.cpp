/*
 -> 부모를 통해 자식의 조상 관련 수치 값을 얻어 비교하는 bfs
 -> string name을 key 값을 잡고 관련 수치를 value 값으로 잡아 map을 이용함
 -> 유토피아를 세운 사람의 자식 외의 사람은 다 0.
 -> 처음에 유토피아를 세운 사람만 1로 시작하여 그 밑에 자식들만 queue에 넣어줌.
 */

#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int N, M;
string root;
map<string, double> p;

string arr[50][3];

int main() {
    cout << "start" << endl;
    cin.tie(NULL);
    ios::sync_with_stdio("False");
    
    cin >> N >> M;
    cin >> root;
    
    for(int i = 0; i < N; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        p.insert(make_pair(a, 0)); //자식이름, 수치
        arr[i][0] = a, arr[i][1] = b, arr[i][2] = c; //가족 정보(자식 이름, 부모 두명)
    }
    
    p[root] = 1; //유토피아를 세운 사람의 value를 1로 잡음.
    queue<string> q;
    q.push(root);
    while(!q.empty()) {
        int queSize = q.size();
        for(int k = 0; k < queSize; k++) {
            string name = q.front();
            q.pop();
            for(int i = 0; i < N; i++) {
                if(arr[i][1] == name || arr[i][2] == name) {
                    p[arr[i][0]] = (p[arr[i][1]] + p[arr[i][2]]) / 2;
                    q.push(arr[i][0]);
                }
            }
        }
    }
    
    double mx = -1;
    string result;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if(p[s] > mx) {
            result = s;
            mx = p[s];
        }
    }
    cout << result << "\n";
    return 0;
}
