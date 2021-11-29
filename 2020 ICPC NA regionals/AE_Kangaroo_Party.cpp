#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> loc(n);
    for(int & i : loc) cin >> i;
    long long ans = 1e9;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            long long curr = 0;
            for(int k = 0; k < n; k++){
                long long dist1 = loc[k] - loc[i]; dist1 *= dist1;
                long long dist2 = loc[k] - loc[j]; dist2 *= dist2;
                curr += min(dist1, dist2);
            }
            ans = min(ans, curr);
        }
    }
    cout << ans << '\n';
}