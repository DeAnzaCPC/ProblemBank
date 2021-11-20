#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int totalVotes = 0, winner = -1, maxVotes = 0;
    for(int i = 1; i <= n; i++){
        int votes; cin >> votes;
        totalVotes += votes;
        if(votes > maxVotes) {
            winner = i;
            maxVotes = votes;
        } else if(votes == maxVotes){
            winner = -1;
        }
    }
    if(winner == -1) {
        cout << "no winner\n";
        return;
    }
    if(maxVotes*2 > totalVotes){
        cout << "majority winner ";
    } else {
        cout << "minority winner ";
    }
    cout << winner << '\n';
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