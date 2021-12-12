#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    long long x = 0, y = 0;
    string direction;
    long long val;
    while(cin >> direction >> val){
        if(direction == "forward"){
            x += val;
        } else {
            y += val * (direction == "up" ? -1 : 1);
        }
    }
    cout << x * y << '\n';
}