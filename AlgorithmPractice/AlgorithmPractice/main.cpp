/*
 2번 문제 설명
 서울시에 일직선 모양의 새로운 도로가 생겼습니다. 새로운 도로의 전체 길이는 l이고 도로에는 총 n개의 가로등이 세워졌습니다. 이 도로의 모든 가로등에 전구를 사서 달려고 합니다. 전구를 선택하는 기준은 다음과 같습니다.
 1. 전구는길의좌측,우측방향으로각각d길이만큼길을밝힐수있고,d는자연수입니다. 2. 모든 가로등에는 같은 종류(d 값이 같은)의 전구를 달아야 합니다.
 
 board
 nums
 result
 [[11,13,15,16],[12,1,4,3],[10,2,7,8],[5,14,6,9]]
 [14,3,2,4,13,1,16,11,5,15]
 3
 [[6,15,17,14,23],[5,12,16,13,25],[21,4,2,1,22], [10,20,3,18,8],[11,9,19,24,7]]
 [15,7,2,25,9,16,12,18,5,4,10,13,20]
 2
 
 3. 안전을 위하여 도로위에 어두운 부분이 있어서는 안 됩니다.
 이때, d 값이 충분히 크다면 전체 도로를 밝게 비출 수 있지만, d 값이 작아진다면 도로 위에 빛이 닿지 않는 부분이 생길 수도 있습니다. 따라서, 도로 위에 어두운 부분이 생기지 않도록 하는 d 값 중 최솟값을 구하려고 합니다. 전체 도로의 길이 l, 가로등이 세워져 있는 위치가 들어있는 배열 v가 매개변수로 주어질 때, 위의 모든 조건을 만족하는 d 의 최솟값을 return 하도록 solution 함수를 완성해주세요.
 제한사항
 l은 1 이상 1,000,000,000 이하의 자연수입니다.
 v에는 가로등의 위치정보가 들어있습니다.
 가로등의 위치는 0 이상 l 이하의 정수이며, 같은 위치에 2개 이상의 가로등이 있는 경우는 주어지지 않습니다. 가로등의 개수는 1이상 1,000 이하의 자연수입니다.
 입출력 예
 입출력 예 설명
 입출력 예 #1 d가 3보다 작은 경우(아래 그림의 경우 d = 2) 다음과 같이 밝히지 못하는 부분이 생기게 됩니다.
 따라서 모든 길을 밝게 비추기 위한 d의 최솟값은 3이 됩니다.
 입출력 예 #2 d가 2보다 작은 경우(아래 그림의 경우 d = 1) 다음과 같이 2 위치에 있는 가로등이 길의 시작 부분을
 밝히지 못하게 됩니다.
 따라서 모든 길을 밝게 비추기 위한 d의 최솟값은 2가 됩니다.
 
 l
 v
 output
 15
 [15,5,3,7,9,14,0]
 3
 5
 [2,5]
 2
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int l, vector<int> v) {
    int answer = 1;
    int distance = 0;
    bool zeroAdded = false;
    bool maxAdded = false;
    
    sort(v.begin(), v.end());
    
    if (v[0] != 0) {
        zeroAdded = true;
        v.insert(v.begin(), 0);
    }
    
    if (v[v.size() - 1] != l) {
        maxAdded = true;
        v.push_back(l);
    }
    
    for (int i = 0; i < v.size() - 1; i++) {
        if (i == 0 && zeroAdded) {
            distance = abs(v[i] - v[i + 1]);
        }
        else if (i == v.size() - 2 && maxAdded) {
            distance = abs(v[i] - v[i + 1]);
        }
        else {
            if (abs(v[i] + v[i + 1]) % 2 == 0) {
                distance = abs(v[i] - v[i + 1]) / 2;
            }
            else {
                distance = (abs(v[i] - v[i + 1]) / 2) + 1;
            }
        }
        
        if (answer < distance) {
            answer = distance;
        }
    }
    
    return answer;
}

int main() {
    int length1 = 15;
    vector<int> input1;
    input1.push_back(15);
    input1.push_back(5);
    input1.push_back(3);
    input1.push_back(7);
    input1.push_back(9);
    input1.push_back(14);
    input1.push_back(0);
    
    int length2 = 5;
    vector<int> input2;
    input2.push_back(2);
    input2.push_back(5);
    
    cout << solution(length1, input1) << endl;
    cout << solution(length2, input2) << endl;
    return 0;
}
