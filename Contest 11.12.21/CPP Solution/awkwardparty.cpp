#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<int,int> m;
    int awkMin = n;
    for(int i = 0; i < n; i++){
        int lang; cin >> lang;
        if(m.count(lang)){
            awkMin = min(awkMin, i - m[lang]);
        }
        m[lang] = i;
    }
    cout << awkMin << '\n';
}