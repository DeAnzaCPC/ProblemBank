#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int aim = 0, x = 0, y = 0;
    string direction;
    int val;
    while(cin >> direction >> val){
        if(direction == "forward"){
            x += val;
            y += aim * val;
        } else {
            if(direction == "up"){
                aim -= val;
            } else {
                aim += val;
            }
        }
    }
    cout << x * y << '\n';
}