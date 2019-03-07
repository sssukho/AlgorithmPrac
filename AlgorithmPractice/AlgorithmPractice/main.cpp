#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
vector<int> comb;
vector<int> idx;
vector<int> output;

int t, k;

int main() {
    cout << "start" << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    while(true) {
        s.clear();
        comb.clear();
        idx.clear();
        
        cin >> k;
        if(k == 0)
            break;
        
        for(int i = 0; i < k; i++) {
            int input;
            cin >> input;
            s.push_back(input);
        }
        
        for(int i = 0; i < 6; i++)
            comb.push_back(1);
        
        for(int i = 0; i < (int)s.size() - 6; i++)
            comb.push_back(0);
        
        do {
            idx.clear();
            for(int i = 0; i < (int)s.size(); i++) {
                if(comb[i] == 1) {
                    idx.push_back(i);
                }
            }
            
            for(int i = 0; i < (int)idx.size(); i++)
                output.push_back(s[idx[i]]);
            
            sort(output.begin(), output.end());
            
            for(int i = 0; i < (int)output.size(); i++) {
                cout << output[i] << ' ';
            }
            output.clear();
            cout << "\n";
        }while(prev_permutation(comb.begin(), comb.end()));
        cout << "\n";
    }
    
    return 0;
}
