//
//  프로그래머스_숫자게임_level3.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/09/08.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    
    int aIndex = 0;
    int bIndex = 0;
    
    if(A[A.size()-1] >= B[0])
        return 0;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[aIndex] < B[bIndex]) {
            bIndex++;
            answer++;
        }
        aIndex++;
    }
    
    return answer;
}

int main() {
    vector<int> a1, a2, b1, b2;
    
    a1.push_back(5);
    a1.push_back(1);
    a1.push_back(3);
    a1.push_back(7);
    
    b1.push_back(2);
    b1.push_back(2);
    b1.push_back(6);
    b1.push_back(8);
    
    a2.push_back(2);
    a2.push_back(2);
    a2.push_back(2);
    a2.push_back(2);
    
    b2.push_back(1);
    b2.push_back(1);
    b2.push_back(1);
    b2.push_back(1);
    
    cout << solution(a1, b1) << endl;
    cout << solution(a2, b2) << endl;
    
    return 0;
}

