#include <bits/stdc++.h>
using namespace std;

int rMax, cMax;
vector<string> grid;

void dfs(int i, int j){
    if(i == rMax - 1 || grid[i + 1][j] == 'V') return;
    if(grid[i + 1][j] == '.'){
        grid[i + 1][j] = 'V';
        dfs(i + 1, j);
    } else if(grid[i + 1][j] == '#'){
        if(j > 0 && grid[i][j - 1] == '.'){
            grid[i][j - 1] = 'V';
            dfs(i, j - 1);
        }
        if(j + 1 < cMax && grid[i][j + 1] == '.'){
            grid[i][j + 1] = 'V';
            dfs(i, j + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> rMax >> cMax;
    grid.resize(rMax);
    for(string& s : grid) cin >> s;

    // water falls off bottom of grid, so rMax - 1
    for(int i = 0; i < rMax - 1; i++){
        for(int j = 0; j < cMax; j++){
            if(grid[i][j] != 'V') continue;
            if(grid[i + 1][j] == 'V') continue;
            // dfs on all water blocks not in last row
            // if the block underneath is not water already
            dfs(i, j);
        }
    }

    for(string s : grid) cout << s << '\n';
}