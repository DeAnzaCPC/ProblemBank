#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int rMax, cMax; cin >> rMax >> cMax;
    vector<string> grid(rMax);
    for(string& s : grid) cin >> s;
    deque<pair<int,int>> q;
    for(int i = 0; i < rMax; i++){
        for(int j = 0; j < cMax; j++){
            if(grid[i][j] != 'V') continue;
            if(i < rMax - 1 && grid[i + 1][j] == 'V') continue;
            q.push_back({i, j});
        }
    }
    while(!q.empty()){
        // using structured bindings to rename pair<int,int>
        auto [i, j] = q.front();
        q.pop_front();
        if(i == rMax - 1) continue;
        if(grid[i + 1][j] == '.'){
            grid[i + 1][j] = 'V';
            q.push_back({i + 1, j});
        } else if(grid[i + 1][j] == '#'){
            if(j > 0 && grid[i][j - 1] == '.'){
                grid[i][j - 1] = 'V';
                q.push_back({i, j - 1});
            }
            if(j + 1 < cMax && grid[i][j + 1] == '.'){
                grid[i][j + 1] = 'V';
                q.push_back({i, j + 1});
            }
        }
    }

    for(string s : grid) cout << s << '\n';
}