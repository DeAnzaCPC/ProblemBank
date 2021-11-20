#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;

    // dist = sqrt(a^2 + b^2)
    // calculate solutions to 2018^2 = a^2 + b^2
    int target = 2018 * 2018;
    vector<pair<int,int>> vp;
    unordered_map<int, vector<int>> m;
    for(int i = -2018; i <= 2018; i++){
        if(m.count(target - (i*i))){
            for(int num : m[target - (i*i)]){
                vp.push_back(make_pair(i, num));
                vp.push_back(make_pair(num, i));
            }
        }
        m[i*i].push_back(i);
    }
    // for(auto p : vp){
    //     cout << p.first << ' ' << p.second << '\n';
    // }
    m.clear();

    int ans = 0;
    set<pair<int,int>> s;
    for(int i = 0; i < n; i++){
        pair<int,int> nextP;
        cin >> nextP.first >> nextP.second;
        for(pair<int,int> p : vp){
            // pair p is a copy
            p.first += nextP.first;
            p.second += nextP.second;
            if(s.count(p)) ans++;
        }
        s.insert(nextP);
    }
    cout << ans << '\n';
}