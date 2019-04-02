/*
 모든 사람마다 계단으로 가는 시간 +1을 벡터에 저장하고 그 백터를 오름차순으로 정렬한다.
 그 다음 for문 돌면서 계단 내려가는 시간을 더해주는데 만약에 계단에 들억간 사람이 3명 보다 많은 경우엔
 (3 인덱스 전 사람의 총 걸린 시간 - 본인 걸린 시간 + 계단 내려가는 시간)을 더해준다.
 그렇게 해서 가장 오래 걸린 시간을 ans에 저장
 그리고 result 최소값 갱신
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 11
const int INF = 987654321;

struct pos_people {
    int y;
    int x;
};

struct pos_stair {
    int y;
    int x;
    int time;
};

int T, N;
int map[MAX][MAX];
vector<pos_people> people;
vector<pos_stair> stair;
vector<int> comb;
vector<int> distance1;
vector<int> distance2;

int getTimeToStair(pos_people p, pos_stair s) {
    int pr = p.y;
    int pc = p.x;
    int sr = s.y;
    int sc = s.x;
    
    return abs(pr-sr) + abs(pc-sc) + 1;
}

int main() {
    cout << "start" << endl;
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        people.clear();
        stair.clear();
        
        cin >> N;
        
        int result = INF;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
                
                if(map[i][j] == 1) {
                    people.push_back({i, j});
                }
                
                
                if(map[i][j] >= 2)
                    stair.push_back({i, j, map[i][j]});
            }
        }
        
        //한쪽으로 다 쏠린 경우도 생각해야하기 때문에 0부터 모든 사람 ㅇㅇ
        for(int i = 0; i <= people.size(); i++) {
            comb.clear();
            
            for(int j = 0; j < i; j++) {
                comb.push_back(1);
            }
            
            for(int j = 0; j < people.size() - i; j++) {
                comb.push_back(0);
            }
            
            do {
                distance1.clear();
                distance2.clear();
                
                for(int j = 0; j < people.size(); j++) {
                    if(comb[j] == 1) {
                        distance1.push_back(getTimeToStair(people[j], stair[0]));
                    }
                    else if(comb[j] == 0) {
                        distance2.push_back(getTimeToStair(people[j], stair[1]));
                    }
                }
                
                sort(distance1.begin(), distance1.end());
                sort(distance2.begin(), distance2.end());
                
                int cnt = 0;
                int ans = 0;
                
                for(int j = 0; j < distance1.size(); j++) {
                    cnt++;
                    if(cnt <= 3)
                        distance1[j] += stair[0].time;
                    
                    else {
                        if(distance1[j-3] - distance1[j] > 0) {
                            distance1[j] += (distance1[j-3]-distance1[j]+stair[0].time);
                        }
                        else {
                            distance1[j] += stair[0].time;
                        }
                    }
                    
                    ans = max(ans, distance1[j]);
                }
                
                cnt = 0;
                
                for(int j = 0; j < distance2.size(); j++) {
                    cnt++;
                    
                    if(cnt <= 3)
                        distance2[j] += stair[1].time;
                    
                    else {
                        if(distance2[j-3] - distance2[j] > 0) {
                            distance2[j] += (distance2[j-3]-distance2[j]+stair[1].time);
                        }
                        else {
                            distance2[j] += stair[1].time;
                        }
                    }
                    
                    ans = max(ans, distance2[j]);
                }
                
                result = min(result, ans);
            }while(prev_permutation(comb.begin(), comb.end()));
            
        }
        
        printf("#%d %d\n", t, result);
    }
    
    
    return 0;
}
