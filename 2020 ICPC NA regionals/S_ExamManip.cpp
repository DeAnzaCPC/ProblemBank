#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<string> test(n);
    for(string & s : test) cin >> s;
    int maxScore = 0;
    for(int num = 0; num < (1<<k); num++){
        vector<bool> examAns(k);
        for(int bit = 0; bit < k; bit++){
            if(num >> bit & 1) examAns[bit] = true;
        }
        int currMin = 1e9;
        for(string s : test){
            int currScore = 0;
            for(int q = 0; q < k; q++){
                if((s[q] == 'T') == examAns[q]) currScore++;
            }
            currMin = min(currMin, currScore);
        }
        maxScore = max(maxScore, currMin);
    }
    cout << maxScore << '\n';
}