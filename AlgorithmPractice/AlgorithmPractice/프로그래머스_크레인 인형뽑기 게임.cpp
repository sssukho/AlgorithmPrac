//
//  프로그래머스_크레인 인형뽑기 게임.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/03.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int moveIdx = 0;
    int size = (int) moves.size();
    
    // 바구니
    stack<int> bucket;
    
    while(moveIdx < size) {
        // 크레인을 작동시킨 위치
        int pos = moves[moveIdx] - 1;
        
        for(int i = 0; i < board.size(); i++) {
            int doll = board[i][pos];
            // 인형 존재할 때
            if(doll != 0) {
                // 바구니가 비어있지 않으면 짝이 맞는지 체크
                if(!bucket.empty()) {
                    if(bucket.top() == doll) {
                        answer += 2;
                        bucket.pop();
                    }
                    else {
                        bucket.push(doll);
                    }
                }
                
                else {
                    bucket.push(doll);
                }
                
                board[i][pos] = 0;
                break;
            }
        }
        
        moveIdx++;
    }
    
    return answer;
}
