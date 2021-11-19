#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string before, after; cin >> before >> after;
    deque<char> bef, aft;
    for(char c : before) bef.push_back(c);
    for(char c : after) aft.push_back(c);
    while(!bef.empty() && !aft.empty()){
        if(bef.front() != aft.front()) break;
        bef.pop_front();
        aft.pop_front();
    }
    while(!bef.empty() && !aft.empty()){
        if(bef.back() != aft.back()) break;
        bef.pop_back();
        aft.pop_back();
    }
    cout << aft.size() << '\n';
}