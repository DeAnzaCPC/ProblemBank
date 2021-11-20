#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // socks, machine capacity, max color diff
    int s, c, k; cin >> s >> c >> k;
    vector<int> color(s);
    for(int & i : color) cin >> i;
    sort(color.begin(), color.end());
    int ans = 1, upperLimit = color[0] + k, currCapacity = 1;
    for(int i = 1; i < s; i++){
        if(color[i] > upperLimit || currCapacity == c){
            ans++;
            currCapacity = 1;
            upperLimit = color[i] + k;
        } else {
            currCapacity++;
        }
    }
    cout << ans << '\n';
}