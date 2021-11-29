#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<bool> chars(26);
    for(char c:s){
        if(chars[c-'a']) {
            cout << "0\n";
            return 0;
        }
        chars[c-'a'] = true;
    }
    cout << "1\n";
}