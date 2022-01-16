#include <bits/stdc++.h>
using namespace std;

void solve(){
    int R, C; cin >> R >> C;
    vector<string> grid(R);
    for(string& s : grid) cin >> s;

    // flip left to right
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C/2; c++){
            swap(grid[r][c], grid[r][C - 1 - c]);
            // manual swap:
            // char temp = grid[r][c];
            // grid[r][c] = grid[r][C - 1 - c];
            // grid[r][C - 1 - c] = temp;
        }
        // alternatively:
        // reverse(grid[r].begin(), grid[r].end());
    }

    // flip top to bottom
    for(int c = 0; c < C; c++){
        for(int r = 0; r < R/2; r++){
            swap(grid[r][c], grid[R - 1 - r][c]);
            // manual swap:
            // char temp = grid[r][c];
            // grid[r][c] = grid[R - 1 - r][c];
            // grid[R - 1 - r][c] = temp;
        }
    }
    // alternatively:
    // reverse(grid.begin(), grid.end());

    for(string s : grid){
        cout << s << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Test " << i << '\n';
        solve();
    }
}