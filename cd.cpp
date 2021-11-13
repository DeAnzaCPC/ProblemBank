#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        unordered_set<int> jack;
        for(int i = 0; i < n; i++){
            int jack_cd; cin >> jack_cd;
            jack.insert(jack_cd);
        }

        int duplicate = 0;
        for(int i = 0; i < m; i++){
            int jill_cd; cin >> jill_cd;
            if(jack.count(jill_cd)) duplicate++;
        }
        cout << duplicate << '\n';
    }
}