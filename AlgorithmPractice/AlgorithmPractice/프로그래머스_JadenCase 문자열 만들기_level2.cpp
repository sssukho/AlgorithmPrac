//
//  프로그래머스_JadenCase 문자열 만들기_level2.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/18.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    
    for(int i = 0; i < s.length(); i++) {
        if(isFirst) {
            if(s[i] >= 'a' && s[0] <= 'z') {
                s[i] = toupper(s[i]);
            }
            isFirst = false;
            continue;
        }
        
        if(s[i] == ' ') {
            isFirst = true;
            continue;
        }
        
        if(!isFirst) {
            s[i] = tolower(s[i]);
        }
    }
    
    answer = s;
    
    return answer;
}

int main() {
    
    string s1 = "3people unFollowed me";
    string s2 = "for the last week";
    
    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
    
    return 0;
}

