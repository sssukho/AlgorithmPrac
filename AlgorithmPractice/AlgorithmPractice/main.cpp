/*
 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
 
 예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
 
 array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
 2에서 나온 배열의 3번째 숫자는 5입니다.
 배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 
 제한사항
 array의 길이는 1 이상 100 이하입니다.
 array의 각 원소는 1 이상 100 이하입니다.
 commands의 길이는 1 이상 50 이하입니다.
 commands의 각 원소는 길이가 3입니다.
 
 [1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
 [1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
 [1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.*/

//입출력 예시
//배열 입력 : [1, 5, 2, 6, 3, 7, 4]
//명령어 입력 : [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
//출력 : [5, 6, 3]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto proc : commands)
    {
        int start = proc[0];
        int end = proc[1];
        int num = proc[2];
        
        vector<int>temp(end - start + 1);
        for (int i = 0; i < end - start + 1;++i)
        {
            temp[i] = array[i + start-1];
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[num-1]);
        
    }
    
    return answer;
}

int main() {
    vector<int> array;
    vector<vector<int>> commands;
    
    string inputArr;
    string inputCmd;
    
    cin >> inputArr;
    cin >> inputCmd;
    
    inputArr.erase(remove(inputArr.begin(), inputArr.end(), ' '), inputArr.end());
    inputCmd.erase(remove(inputCmd.begin(), inputCmd.end(), ' '), inputCmd.end());
    
    for(int i = 0; i < inputArr.size(); i++) {
        array.push_back(inputArr[i]);
    }
    
    for(int i = 0; i < inputCmd.size(); i++) {
        for(int j = 0; j < 3; j++) {
            commands[i][j] = inputCmd[0*3+j];
        }
    }
    
    vector<int> answer = solution(array, commands);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}
