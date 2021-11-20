#include <bits/stdc++.h>
using namespace std;

int findLargestFactor(int n){
    int ans = 1;
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            int r = i, c = n/i;
            if(r > c) break;
            ans = r;
        }
    }
    return ans;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    int row_count = findLargestFactor(n);
    // cout << row_count << endl;
    string ans = "";
    for(int i = 0; i < row_count; i++){
        for(int j = i; j < n; j+=row_count){
            ans.push_back(s[j]);
        }
    }
    cout << ans << endl;
}