#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    for(int i : a){
        if(sum == i * 2){
            cout << i << endl;
            return 0;
        }
    }
    cout << "BAD\n";
}