/*https://programmers.co.kr/learn/courses/30/lessons/42839/*/
//소수찾기

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX 9999999

int isPrime[MAX+1]; //최대 사이즈보다 +1 을 하는 습관을 들여놓는 것이 중요하다 => 편하게 인덱싱하기 위해서.

void sieve_Of_Eratosthenes(int N) {
    for (int i = 2; i <= N; i++) {
        isPrime[i] = 1;    // initialize isPrime[] array
    }
    int sqrtn=sqrt(N); //루트까지만 검사를 해줘도 약수가 있는지 없는지 알 수 있다.
    for (int i = 2; i <= sqrtn; i++) {
        if (!isPrime[i]) continue; //소수가 아니면 다음 for문
        for (int j = i + i; j <= N; j += i) { //소수가 아닌 것들을 0으로 지워나가면서 진행
            isPrime[j] = 0;
        }
    }
}


int solution(string numbers) {
    int answer = 0;
    sieve_Of_Eratosthenes(MAX);
    int l = numbers.size();
    vector<int> v(l);
    for(int i=0; i<l;i++){
        sort(numbers.begin(),numbers.end());
        v[i] = 1; //자릿수를 보기 위해.
        do{
            int j = 1;
            int pr = 0;
            for(int k=0;k<l;k++){
                if(v[k]==1){
                    pr += (numbers[k]-'0')*j;
                    j *= 10;
                }
                else break;
            }
            if (isPrime[pr]==1){
                cout << pr << '\n';
                isPrime[pr] = 2;
                answer++;
            }
        }while(next_permutation(numbers.begin(),numbers.end()));
    }
    
    return answer;
}

int main() {
    string input1 = "17";
    string input2 = "011";
    
    cout << solution(input1) << endl;
    cout << solution(input2) << endl;
    
}
