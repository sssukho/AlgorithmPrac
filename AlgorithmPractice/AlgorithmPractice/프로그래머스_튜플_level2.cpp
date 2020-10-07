//
//  프로그래머스_튜플_level2.cpp
//  AlgorithmPractice
//
//  Created by Sukho Lim on 2020/10/07.
//  Copyright © 2020 Sukho Lim. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    // 맨앞 맨뒤 중괄호 제거
    s.erase(s.begin()+1);
    s.erase(s.end()-1);
    
    string temp = "";
    
    map<int, int> m;
    // {, }, , 일 경우에 숫자들(두 자리 이상일 경우도 있으니)을 맵에 넣으면서 카운팅을 해준다.
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if(temp != "") {
                m[stoi(temp)] += 1;
                temp = "";
            }
            continue;
        }
        else {
            temp += s[i];
        }
    }
    
    answer.resize(m.size());
    // 맵에서 카운팅 된 횟수는 맵의 사이즈와 같다. 따라서 아래와 같이 작성해주면
    // 원하는 답과 거꾸로 된 결론이 나오게 되는데, 이 때 reverse 메소드를 활용해서
    // 원하는 결과값이 나오게 answer 벡터를 역순으로 바꿔준다.
    for(auto it = m.begin(); it != m.end(); it++) {
        answer[it->second-1] = it->first;
    }
    
    reverse(answer.begin(), answer.end());
    
    
    return answer;
}
