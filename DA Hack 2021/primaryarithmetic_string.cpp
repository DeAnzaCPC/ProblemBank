#include <bits/stdc++.h>
using namespace std;

int n;
void pad(string & s){
    int pad_count = n - s.size();
    string zero = "";
    while(pad_count--){
        zero.push_back('0');
    }
    s = zero + s;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2;
    while(true){
        cin >> s1 >> s2;
        if(s1 == "0" && s2 == "0") break;
        n = max(s1.size(), s2.size())+1;
        // pad strings with zeros
        pad(s1), pad(s2);
        int carry = 0, ans = 0;
        for(int i = n-1; i>=0; i--){
            int add = s1[i]-'0' + s2[i]-'0' + carry;
            if(add > 9){
                carry = add/10;
                ans++;
            } else {
                carry = 0;
            }
        }
        if(ans){
            if(ans == 1){
                cout << "1 carry operation.\n";
            } else {
                cout << ans << " carry operations.\n";
            }
        } else {
            cout << "No carry operation.\n";
        }
    }
}