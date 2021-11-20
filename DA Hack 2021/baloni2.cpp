#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> h(n);
    for(int&i:h) cin >> i;
    vector<bool> used(n, false);
    unordered_map<int, deque<int> > m;
    for(int i = 0; i < n; i++){
        m[h[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = true;
            m[h[i]].pop_front();
            if(m[h[i]].empty()) m.erase(h[i]);
        }
        if(m.count(h[i]-1)==0 || m[h[i]-1].empty()){
            ans++;
            continue;
        }
        int use = m[h[i]-1].front();
        used[use] = true;
        m[h[i]-1].pop_front();
        if(m[h[i]-1].empty()) m.erase(h[i]-1);
    }
    cout << ans << endl;
}