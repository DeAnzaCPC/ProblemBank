#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string start; cin >> start;
    string end = start;
    next_permutation(end.begin(), end.end());

    if(end > start) cout << end << '\n';
    else cout << "0\n";
}