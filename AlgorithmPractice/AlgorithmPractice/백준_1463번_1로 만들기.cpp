#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000000

int cache[MAX];

int main() {
    cout << "start" << endl;
    int input;
    cin >> input;
    
    cache[1] = 0;
    for(int i = 2; i <= input; i++) {
        cache[i] = cache[i-1] + 1;
        if(i % 3 == 0)
            cache[i] = min(cache[i], cache[i/3] + 1);
        else if(i % 2 == 0)
            cache[i] = min(cache[i], cache[i/2] + 1);
    }
    
    cout << cache[input] << endl;
    
    return 0;
}
