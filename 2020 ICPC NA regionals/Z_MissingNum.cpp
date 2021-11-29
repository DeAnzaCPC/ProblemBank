#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int currIndex = 0;
    for(int i = 1; i <= n; i++){
        string curr = to_string(i);
        for(int j = currIndex; j < currIndex + curr.size(); j++){
            if(s[j] != curr[j - currIndex]){
                cout << i << '\n';
                return 0;
            }
        }
        currIndex += curr.size();
    }
}