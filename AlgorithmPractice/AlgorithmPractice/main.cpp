#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char map[5][5];
bool visited[5][5];

int sNum; //이다솜파 명수
int cnt; //총 여학생 명수

vector<char> students;
vector<int> comb;

bool flag; //이다솜파가 4명이상인지 아닌지
bool isFinishied; //총 여학생 명수가 7명인지 아닌지

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x) {
    if(cnt == 7) {
        isFinishied = true;
        if(sNum >= 4)
            flag = true;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int my = y + dy[i];
        int mx = x + dx[i];
        
        if(my >= 0 && my < 5 && mx >= 0 && mx < 5) {
            if(!visited[my][mx] && comb[(my*5)+mx] == 1) {
                visited[my][mx] = true;
                cnt++;
                
                if(students[(my*5) + mx] == 'S') {
                    sNum++;
                    dfs(my, mx);
                }
                else {
                    dfs(my, mx);
                }
                if(isFinishied)
                    return;
            }
        }
    }
}

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> map[i][j];
            students.push_back(map[i][j]);
        }
    }
    
    for(int i = 0; i < 7; i++)
        comb.push_back(1);
    
    for(int i = 0; i < 18; i++)
        comb.push_back(0);
    
    int result = 0;
    do {
        flag = false;
        
        for(int i = 0; i < 25; i++) {
            if(comb[i] == 1) {
                if(!flag) {
                    isFinishied = false;
                    memset(visited, false, sizeof(visited));
                    visited[i/5][i%5] = true;
                    cnt = 1;
                    sNum = 0;
                    if(students[i] == 'S'){
                        sNum++;
                        dfs(i / 5, i % 5);
                    }
                    else
                        dfs(i / 5, i % 5);
                }
                if(!flag)
                    break;
                else {
                    result++;
                    break;
                }
            }
        }
        
    } while(prev_permutation(comb.begin(), comb.end()));
    
    cout << result << endl;
    return 0;
}
