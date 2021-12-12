#include <bits/stdc++.h>
using namespace std;

vector<int> basinSizes;
int iMax, jMax;

void dfs(int i, int j, int& basinSize, const vector<string>& grid, vector<vector<bool>>& used){
    vector<pair<int,int>> directions = {
        {i - 1, j},
        {i + 1, j},
        {i, j - 1},
        {i, j + 1}
    };
    for(auto p : directions){
        if(p.first < 0
        || p.second < 0
        || p.first >= iMax
        || p.second >= jMax) continue;
        if(used[p.first][p.second]
        || grid[p.first][p.second] == '9') continue;
        used[p.first][p.second] = true;
        basinSize++;
        dfs(p.first, p.second, basinSize, grid, used);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> grid;
    string line;
    while(getline(cin, line)) grid.push_back(line);

    iMax = grid.size(), jMax = grid[0].size();
    vector<vector<bool>> used(iMax, vector<bool>(jMax));
    
    for(int i = 0; i < iMax; i++){
        for(int j = 0; j < jMax; j++){
            if(used[i][j] || grid[i][j] == '9') continue;
            used[i][j] = true;
            int basinSize = 1;
            dfs(i, j, basinSize, grid, used);
            basinSizes.push_back(basinSize);
        }
    }
    sort(basinSizes.rbegin(), basinSizes.rend());
    cout << (long long)basinSizes[0] * basinSizes[1] * basinSizes[2] << '\n';
}