//DFS, BFS 문제
//https://programmers.co.kr/learn/courses/30/lessons/43165

/*
 n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.
 
 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3
 
 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.
 
 제한사항
 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
 각 숫자는 1 이상 50 이하인 자연수입니다.
 타겟 넘버는 1 이상 1000 이하인 자연수입니다.
 
 입출력 예
 numbers    target    return
 [1, 1, 1, 1, 1]    3    5
 
 입출력 예 설명
 문제에 나온 예와 같습니다.
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int total;

//DFS에서는 어떤 조건을 줘서 종료를 시켜야하는지 생각해야함.
//어떤 인자로 넘겨주는게 필요한지도 생각.

void DFS(vector<int> &numbers, int &target, int sum, int n) { //n은 깊이
    if(n >= numbers.size()) {
        if(sum == target)
            total = total + 1;
        return;
    }
    
    DFS(numbers, target, sum + numbers[n], n+1); //그래프를 그려보면 됨.
    DFS(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    //제한사항1. 주어지는 숫자들의 개수
    if(numbers.size() < 2 || numbers.size() > 20)
        return -1;

    //제한사항2. 타겟넘버 범위
    if(target < 1 || target > 1000)
        return -1;

    //제한사항3. 주어지는 숫자들의 범위
    for(auto x : numbers) {
        if(x < 1 || x > 50)
            return -1;
    }
    
    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);
    
    answer = total;

    return answer;
}


int main() {
    vector<int> vec(5,1);
    int target = 3;

    cout << solution(vec, target) << endl;
}
