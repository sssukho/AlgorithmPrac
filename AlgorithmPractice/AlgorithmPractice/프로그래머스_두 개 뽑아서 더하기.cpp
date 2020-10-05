//
//  프로그래머스_두 개 뽑아서 더하기.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/06.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    
    vector<int> comb;
    for(int i = 0; i < 2; i++)
        comb.push_back(1);
    
    for(int i = 0; i < numbers.size()-2; i++)
        comb.push_back(0);
    
    sort(comb.begin(), comb.end());
    
    do {
        int temp = 0;
        for(int i = 0; i < comb.size(); i++) {
            if(comb[i] == 1) {
                temp += numbers[i];
            }
        }
        s.insert(temp);
        
    }while(next_permutation(comb.begin(), comb.end()));
    
    
    set<int>::iterator it;
    
    for(it = s.begin(); it != s.end(); it++) {
        answer.push_back(*it);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
