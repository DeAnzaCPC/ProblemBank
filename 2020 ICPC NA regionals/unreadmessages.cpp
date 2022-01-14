#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    map<int,int> lastRead;
    
    long long currTotal = 0;
    for(int i = 1; i <= m; i++){
        int s; cin >> s;
        currTotal += n;
        int subtract = i;
        if(lastRead.count(s)){
            subtract -= lastRead[s];
        }
        lastRead[s] = i;
        currTotal -= subtract;
        cout << currTotal << '\n';
    }
}