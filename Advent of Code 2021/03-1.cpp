#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> reports;
    string s;
    while(cin >> s){
        reports.push_back(s);
    }

    string gamma = "";
    int n = reports[0].size();
    for(int digit = 0; digit < n; digit++){
        int countOne = 0;
        for(string s : reports){
            if(s[digit] == '1') countOne++;
        }
        if(countOne * 2 >= reports.size()){
            gamma.push_back('1');
        } else {
            gamma.push_back('0');
        }
    }

    long long gammaVal = 0, epsilonVal = 0;
    for(int i = 0; i < n; i++){
        int complement = n - 1 - i;
        if(gamma[i] == '1') gammaVal += (1 << complement);
        else epsilonVal += (1 << complement);
    }
    cout << gammaVal * epsilonVal << '\n';
}