#include <bits/stdc++.h>
using namespace std;

int rMax, cMax;

void dfs(vector<string>& grid, int i, int j){
    if(i == rMax - 1 || grid[i + 1][j] == 'V') return;
    if(grid[i + 1][j] == '.'){
        grid[i + 1][j] = 'V';
        dfs(grid, i + 1, j);
    } else {
        if(j > 0 && grid[i][j - 1] == '.'){
            grid[i][j - 1] = 'V';
            dfs(grid, i, j - 1);
        }
        if(j + 1 < cMax && grid[i][j + 1] == '.'){
            grid[i][j + 1] = 'V';
            dfs(grid, i, j + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> rMax >> cMax;
    vector<string> grid(rMax);
    for(string& s : grid) cin >> s;
    for(int i = 0; i < rMax - 1; i++){
        for(int j = 0; j < cMax; j++){
            if(grid[i][j] != 'V') continue;
            if(grid[i + 1][j] == 'V') continue;
            dfs(grid, i, j);
        }
    }
    for(string s : grid) cout << s << '\n';
}