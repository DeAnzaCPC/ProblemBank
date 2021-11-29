#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    long long scoreTotal = 0;
    for(int i = 0; i < k; i++){
        int score; cin >> score;
        scoreTotal += score;
    }
    int diff = n - k;
    long long maxScore = scoreTotal + (diff * 3);
    long long minScore = scoreTotal - (diff * 3);
    cout << fixed << setprecision(6);
    cout << (long double)minScore / n << ' '
         << (long double)maxScore / n << '\n';
}