//bfs, dfs 네트워크
//https://programmers.co.kr/learn/courses/30/lessons/43162

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 201

int check[MAX] = {0};
int net[MAX][MAX] = {0};

void DFS(int x, int n) {
    check[x] = 1;
    
    for(int i = 0; i < n; i++) {
        if(net[x][i] == 1 && check[i] == 0)
            DFS(i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(computers[i][j] == 1)
                net[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(check[i] == 0) {
            DFS(i, n);
            answer = answer + 1;
        }
        
    }
    
    return answer;
}


int main() {
    vector<vector<int>> computer1;
    vector<vector<int>> computer2;
    
    computer1.resize(3);
    computer2.resize(3);
    
    //예제 1 인풋 세팅
    computer1[0].push_back(1);
    computer1[0].push_back(1);
    computer1[0].push_back(0);
    computer1[1].push_back(1);
    computer1[1].push_back(1);
    computer1[1].push_back(0);
    computer1[2].push_back(0);
    computer1[2].push_back(0);
    computer1[2].push_back(1);
    
    //예제2 인풋 세팅
    computer2[0].push_back(1);
    computer2[0].push_back(1);
    computer2[0].push_back(0);
    computer2[1].push_back(1);
    computer2[1].push_back(1);
    computer2[1].push_back(1);
    computer2[2].push_back(0);
    computer2[2].push_back(1);
    computer2[2].push_back(1);
    
    //예제1 출력
    cout << solution(3, computer1) << endl;
    cout << "--------------------------------" << endl;
    
    
    //예제2 출력
    //cout << solution(3, computer2) << endl;
    
    return 0;
}
