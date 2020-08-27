#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// & : 대응하는 두 비트가 모두 1일 때 1을 반환
// | : 대응하는 두 비트가 모두 1 또는 하나라도 1일 때 1을 반환
// ^ : 대응하는 두 비트가 서로 다르면 1을 반환
// ~ : 비트의 값을 반전하여 반환

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    printf("start\n");
    int M;
    cin >> M;
    
    int bitMask = 0;
    
    while(M > 0) {
        string op;
        cin >> op;
        
        if(op == "all") {
            for(int i = 1; i <= 20; i++)
                bitMask = bitMask | (1 << i);
            continue;
        }
        
        if(op == "empty") {
            bitMask = 0;
            continue;
        }
        
        int num;
        cin >> num;
        
        if(op == "add") {
            bitMask = bitMask | (1 << num);
        }
        
        else if(op == "remove") {
            bitMask = bitMask & ~(1 << num);
        }
        
        else if(op == "toggle") {
            bitMask ^= (1 << num);
        }
        
        else if(op == "check") {
            if(bitMask & (1 << num))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        
        M--;
    }
    
    
    return 0;
}
