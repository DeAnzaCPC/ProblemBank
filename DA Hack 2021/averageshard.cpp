#include <bits/stdc++.h>
using namespace std;

void solve(){
    int cs, e; cin >> cs >> e;
    vector<long long> cs_students(cs), econ_students(e);
    for(int i = 0; i < cs; i++){
        cin >> cs_students[i];
    }
    for(int i = 0; i < e; i++){
        cin >> econ_students[i];
    }
    long long sumCS = 0, sumE = 0;
    for(long long i:cs_students){
        sumCS += i;
    }
    for(long long i:econ_students){
        sumE += i;
    }
    long double avgCS = (long double)sumCS / cs,
        avgE = (long double)sumE / e;
    long long ans = 0;
    for(int i = 0; i < cs; i++){
        long long newSumCS = sumCS - cs_students[i],
            newSumE = sumE + cs_students[i];
        long double newAvgCS = (long double)newSumCS / (cs-1),
            newAvgE = (long double)newSumE / (e+1);
        if(newAvgCS > avgCS && newAvgE > avgE) ans++;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}