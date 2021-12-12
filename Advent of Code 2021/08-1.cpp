#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

    int ans = 0;
    while(!cin.eof()){
        vector<string> keys(10), code(4);
        for(string & s : keys) cin >> s;
        cin >> code[0];
        for(string & s : code) cin >> s;
        
        for(string s : code){
            if( (s.size() <= 4 && s.size() >= 2)
                || s.size() == 7) ans++;
        }
    }
    cout << ans << '\n';
}