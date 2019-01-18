//https://programmers.co.kr/learn/courses/30/lessons/12977
//프로그래머스 2017 서머코딩 소수 만들기

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 3000
bool isPrime[MAX];

void eratosthenes() {
    for(int i = 2; i <= MAX; i++){
        isPrime[i] = true;
    }
    
    int sqrtn = sqrt(MAX);
    
    for(int i = 2; i <= sqrtn; i++) {
        if(isPrime[i]){
            for(int j = i + i; j <= MAX; j=j+i) {
                isPrime[j] = false;
            }
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    
    eratosthenes();
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            for(int k = j+1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if(isPrime[sum])
                    answer++;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(7);
    nums2.push_back(6);
    nums2.push_back(4);
    
    cout << solution(nums1) << endl;
    cout << solution(nums2) << endl;
    
    return 0;
}
