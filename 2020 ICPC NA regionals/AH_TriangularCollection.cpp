#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> sides(n);
    for(long long & ll : sides) cin >> ll;
    sort(sides.begin(), sides.end());
    long long ans = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            int countValid = 0;
            for(int k = j + 1; k < n; k++){
                if(sides[i] + sides[j] <= sides[k]) break;
                countValid++;
            }
            // every unique subset excluding {None} is valid
            ans += (1ll << countValid) - 1;
        }
    }
    cout << ans << '\n';
}