#include <bits/stdc++.h>
using namespace std;

void set_below_10(vector<vector<int>>& grid){
    int n = grid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] > 9) grid[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    const int n = 10, steps = 100;

    vector<string> str_grid(n);
    for(string& s : str_grid) cin >> s;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = str_grid[i][j] - '0';
        }
    }
    int ans = 0;
    for(int step = 1; step <= steps; step++){
        deque<pair<int,int>> flash;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid[i][j]++;
                if(grid[i][j] > 9){
                    flash.push_back({i, j});
                }
            }
        }
        while(!flash.empty()){
            pair<int,int> curr = flash.front();
            flash.pop_front();
            ans++;
            vector<pair<int,int>> directions = {
                {curr.first - 1, curr.second - 1},
                {curr.first - 1, curr.second},
                {curr.first - 1, curr.second + 1},
                {curr.first, curr.second - 1},
                {curr.first, curr.second + 1},
                {curr.first + 1, curr.second - 1},
                {curr.first + 1, curr.second},
                {curr.first + 1, curr.second + 1}
            };
            for(pair<int,int> p : directions){
                if(p.first < 0
                || p.second < 0
                || p.first >= n
                || p.second >= n) continue;
                if(++grid[p.first][p.second] == 10){
                    flash.push_back(p);
                }
            }
        }
        set_below_10(grid);
        if(step % 10 == 0) cout << ans << '\n';
    }
}