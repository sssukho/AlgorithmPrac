#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    int size = arrangement.size(); //괄호의 개수
    
    stack<char> st;
    
    for(int i = 0; i < size; i++) {
        int beforeIndex = i - 1;
        //여는 괄호 일때
        if(arrangement[i] == '(') {
            st.push(arrangement[i]);
        }
        //닫는 괄호 일때
        else {
            st.pop();
            //레이저 일때
            if(arrangement[beforeIndex] == '(')
                answer = answer + st.size();
            //막대 일때
            else
                answer = answer + 1;
        }
    }
    
    return answer;
}

int main() {
    string input = "()(((()())(())()))(())";
    
    cout << solution(input) << endl;
}
