#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> count(9, vector<int>(9));
    for(int i = 1; i < n; i++){
        count[s[i - 1] - '1'][s[i] - '1']++;
    }

    vector<int> keys(9);
    iota(keys.begin(), keys.end(), 1);
    long long ans = 1e9;
    do{
        long long currAns = keys[s[0] - '1'];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                currAns += (abs(keys[i] - keys[j]) + 1) * (long long)count[i][j];
            }
        }
        ans = min(ans, currAns);
    } while(next_permutation(keys.begin(), keys.end()));
    cout << ans << '\n';
}