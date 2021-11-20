#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> trees(n);
    for(int & i : trees) cin >> i;
    sort(trees.begin(), trees.end(), greater<>());
    int currMax = trees[0];
    for(int i = 1; i < n; i++){
        currMax = max(currMax - 1, trees[i]);
    }
    cout << n + 1 + currMax << '\n';
}