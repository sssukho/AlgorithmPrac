/*
 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
 예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.
 0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.
 
 제한 사항
 numbers의 길이는 1 이상 100,000 이하입니다.
 numbers의 원소는 0 이상 1,000 이하입니다.
 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
 
 입출력 예
 numbers                  return
 [6, 10, 2]               6210
 [3, 30, 34, 5, 9]        9534330
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//참고 : http://bitwise.tistory.com/373
bool compare(string a, string b) {
    if(b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringArr;
    
    for(auto x : numbers) {
        stringArr.push_back(to_string(x));
    }
    
    sort(stringArr.begin(), stringArr.end(), compare);
    
    for(auto iter = stringArr.begin(); iter < stringArr.end(); ++iter)
        answer = answer + *iter;
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}

int main() {
    int input1[3] = {6, 10, 2};
    int input2[5] = {3, 30, 34, 5, 9};
    
    vector<int> vec1;
    vector<int> vec2;
    
    for(auto x : input1) {
        vec1.push_back(x);
    }
    for(auto x: input2) {
        vec2.push_back(x);
    }
    
    cout << solution(vec1) << endl;
    cout << solution(vec2) << endl;
}


