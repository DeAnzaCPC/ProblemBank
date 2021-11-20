#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int start, end;
    bool operator < (const Activity & a2) const {
        if(this->end == a2.end) return this->start < a2.start;
        return this->end < a2.end;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<Activity> v(n);
    for(Activity & a : v) {
        cin >> a.start >> a.end;
    }
    sort(v.begin(), v.end());
    
    map<int,int> m;
    m[0] = k;
    
    int ans = 0;
    for(auto a : v){
        auto it = m.lower_bound(a.start);
        if(it == m.begin()) continue;
        it--;
        m[a.end]++;
        if(it->second == 1) m.erase(it->first);
        else m[it->first]--;
        ans++;
    }
    cout << ans << endl;
}