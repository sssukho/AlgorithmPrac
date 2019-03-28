#include <iostream>
using namespace std;
#define MAX 101

int K; //폭탄 가지고 있는 사람의 번호(~8)
int N; //질문 개수
int T; //i번째 질문을 대답하기까지 걸린 시간(단위:초), 그 플레이어의 대답 Z(T,N,P중 하나)
char Z;
//3분 30초 = 210초
int main() {
    cout << "start" << endl;
    cin >> K; //폭탄 들고 있는 사람 번호
    cin >> N; //질문 개수
    
    int sec = 0;
    while(true) {
        cin >> T >> Z;
        sec = sec + T;
        
        if(sec >= 210)
            break;
        
        if(Z == 'T') {
            K = (K%8) + 1;
        }
        
        else
            continue;
    }
    
    cout << K << endl;
    
    return 0;
}
