#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> cards(n);
    for(int & i : cards) cin >> i;
    sort(cards.begin(), cards.end());
    long long score = cards[0];
    for(int i = 1; i < n; i++){
        if(cards[i] > cards[i-1] + 1) score += cards[i];
    }
    cout << score << '\n';
}