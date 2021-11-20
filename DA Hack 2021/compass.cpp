#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int start, end; cin >> start >> end;
    
    int clockwise = end-start;
    if(clockwise < 0) clockwise+=360;
    int counterclockwise = clockwise-360;

    if(clockwise <= abs(counterclockwise)){
        cout << clockwise << endl;
    } else {
        cout << counterclockwise << endl;
    }
}