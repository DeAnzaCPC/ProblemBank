#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string prev, next; cin >> prev >> next;
    bool increase = prev < next;
    prev = next;
    for(int i = 2; i < n; i++){
        cin >> next;
        if(prev < next != increase){
            cout << "NEITHER\n";
            return 0;
        }
		prev = next;
    }
    cout << (increase?"INCREASING\n":"DECREASING\n");
}