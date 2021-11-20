#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a) cin >> i;
    unordered_map<int, int> m;
    for(int i:a){
        if(m.count(i)){
            m[i]--;
            m[i-1]++;
            if(m[i] == 0) m.erase(i);
        } else {
            m[i-1]++;
        }
    }
    int ans = 0;
    for(pair<int, int> p:m) ans += p.second;
    cout << ans << endl;
}