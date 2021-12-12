#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<int> crabs;
    string line;
    getline(cin, line);
    int currIdx = 0;
    for(int i = 1; i < line.size(); i++){
        if(line[i] != ',') continue;
        crabs.push_back(stoi(line.substr(currIdx, i - currIdx)));
        currIdx = i + 1;
    }
    crabs.push_back(stoi(line.substr(currIdx)));
    
    sort(crabs.begin(), crabs.end());
    int n = crabs.size();
    long long ans = 1e10;
    const int maxI = 2000;
    for(int i = 0; i < maxI; i++){
        long long curr = 0;
        for(int position : crabs){
            long long diff = abs(i - position);
            curr += diff * (diff + 1) / 2;
        }
        ans = min(ans, curr);
    }
    
    cout << ans << '\n';
}