#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 21

int N;
int s[MAX][MAX];
vector<int> comb;
vector<int> cost;

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }
    // N/2가 한 팀의 명수
    for(int i = 0; i < N/2; i++)
        comb.push_back(1);
    
    for(int i = 0; i < N/2; i++)
        comb.push_back(0);
    
    do {
        int team1 = 0;
        int team2 = 0;
        vector<int> start;
        vector<int> link;
        
        for(int i = 0; i < N; i++) {
            if(comb[i] == 1)
                start.push_back(i);
            
            else if(comb[i] == 0)
                link.push_back(i);
        }
        
        for(int i = 0; i < start.size(); i++) {
            for(int j = i+1; j < start.size(); j++) {
                team1 = team1 + s[start[i]][start[j]] + s[start[j]][start[i]];
            }
        }
        
        for(int i = 0; i < link.size(); i++) {
            for(int j = i+1; j < link.size(); j++) {
                team2 = team2 + s[link[i]][link[j]] + s[link[j]][link[i]];
            }
        }
        
        cost.push_back(abs(team1-team2));
    }while(prev_permutation(comb.begin(), comb.end()));
    
    sort(cost.begin(), cost.end());
    
    cout << cost[0] << endl;
    
    return 0;
}
