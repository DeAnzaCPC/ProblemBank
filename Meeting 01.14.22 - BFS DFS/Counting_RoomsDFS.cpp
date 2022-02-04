#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector<string> grid;

void dfs(int i, int j){
    vector<pair<int,int>> directions = {
        {i - 1, j},
        {i + 1, j},
        {i, j - 1},
        {i, j + 1}
    };
    for(auto [nextI, nextJ] : directions){
        if(nextI < 0
        || nextJ < 0
        || nextI >= n
        || nextJ >= m) continue;
        if(grid[nextI][nextJ] == '#') continue;
        grid[nextI][nextJ] = '#';
        dfs(nextI, nextJ);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n);
    for(string& s : grid) cin >> s;

    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') continue;
            rooms++;
            grid[i][j] = '#';
            
            dfs(i, j);
        }
    }

    cout << rooms << '\n';
}