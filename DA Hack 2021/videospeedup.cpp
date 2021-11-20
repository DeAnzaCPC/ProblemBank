#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    double p;
    cin >> n >> p >> k;
    vector<int> time(n);
    for(int&i:time) cin >> i;
    
    double ans = time[0];
    for(int i = 1; i < n; i++){
        int diff = time[i] - time[i-1];
        double speed = (100 + p*i)/100;
        ans += diff * speed;
    }
    double speed = (p*n + 100)/100;
    ans += (k-time[n-1]) * speed;
    cout << fixed << setprecision(9) << ans << endl;
}