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
    int median = crabs[n / 2];
    long long ans = 0;
    for(int position : crabs){
        ans += abs(median - position);
    }
    cout << ans << '\n';
}