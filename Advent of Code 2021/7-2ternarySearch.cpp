#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<int> crabs;
    {    
        string line;
        getline(cin, line);
        int currIdx = 0;
        for(int i = 1; i < line.size(); i++){
            if(line[i] != ',') continue;
            crabs.push_back(stoi(line.substr(currIdx, i - currIdx)));
            currIdx = i + 1;
        }
        crabs.push_back(stoi(line.substr(currIdx)));
    }
    sort(crabs.begin(), crabs.end());
    int n = crabs.size();
    
    int a = crabs[0], b = crabs[n - 1];
    while(b - a > 3){
        long long c = (2*a + b) / 3;
        long long d = (a + 2*b) / 3;
        long long sumC = 0, sumD = 0;
        for(int pos : crabs){
            long long diffC = abs(c - pos);
            sumC += diffC * (diffC + 1) / 2;
            long long diffD = abs(d - pos);
            sumD += diffD * (diffD + 1) / 2;
        }
        if(sumC < sumD){
            b = d;
        } else {
            a = c;
        }
    }

    long long ans = 1e18;
    for(int i = a; i <= b; i++){
        long long curr = 0;
        for(int pos : crabs){
            long long diff = abs(i - pos);
            curr += diff * (diff + 1) / 2;
        }
        ans = min(ans, curr);
    }
    
    cout << ans << '\n';
}