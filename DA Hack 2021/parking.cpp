#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c; cin >> a >> b >> c; //costs
    vector<int> time(101, 0);
    for(int i = 0; i < 3; i++){
        int start, end; cin >> start >> end;
        for(int j = start; j < end; j++){
            time[j]++;
        }
    }
    int ans = 0;
    for(int i:time){
        switch(i){
            case 1: ans += a; break;
            case 2: ans += b*2; break;
            case 3: ans += c*3; break;
            default: break;
        }
    }
    cout << ans << endl;
}