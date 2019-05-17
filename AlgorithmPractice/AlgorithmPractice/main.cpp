#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int, int>> st;
    stack<int> output;
    
    for(int i = 0; i < (int)heights.size(); i++) {
        st.push(make_pair(heights[i], i));
    }
    
    while(!st.empty()) {
        int top = st.top().first;
        int top_idx = st.top().second;
        
        for(int i = top_idx; i >= 0; i--) {
            if(heights[i] > top) {
                output.push(i+1);
                break;
            }
            
            if(i == 0)
                output.push(0);
        }
        
        st.pop();
    }
    
    while(!output.empty()) {
        answer.push_back(output.top());
        output.pop();
    }
    
    return answer;
}

int main() {
    vector<int> h1, h2, h3;
    //h1 = {6, 9, 5, 7, 4};
    h1.push_back(6);
    h1.push_back(9);
    h1.push_back(5);
    h1.push_back(7);
    h1.push_back(4);
    //h2 = {3, 9, 9, 3, 5, 7, 2};
    h2.push_back(3);
    h2.push_back(9);
    h2.push_back(9);
    h2.push_back(3);
    h2.push_back(5);
    h2.push_back(7);
    h2.push_back(2);
    //h3 = {1, 5, 3, 6, 7, 6, 5};
    h3.push_back(1);
    h3.push_back(5);
    h3.push_back(3);
    h3.push_back(6);
    h3.push_back(7);
    h3.push_back(6);
    h3.push_back(5);
    
    vector<int> ans1, ans2, ans3;
    ans1 = solution(h1);
    ans2 = solution(h2);
    ans3 = solution(h3);
    
    for(auto x : ans1)
        cout << x << ' ';
    cout << endl;
    
    for(auto x : ans2)
        cout << x << ' ';
    cout << endl;
    
    for(auto x : ans3)
        cout << x << ' ';
    cout << endl;
    
    return 0;
}
