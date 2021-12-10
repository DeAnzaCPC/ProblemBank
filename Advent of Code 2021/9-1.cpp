#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> grid;
    string line;
    while(getline(cin, line)) grid.push_back(line);
    int iMax = grid.size(), jMax = grid[0].size();
    int ans = 0;
    for(int i = 0; i < iMax; i++){
        for(int j = 0; j < jMax; j++){
            vector<pair<int,int>> directions = {
                {i - 1, j},
                {i + 1, j},
                {i, j - 1},
                {i, j + 1}
            };
            bool lowPoint = true;
            for(auto p : directions){
                if(p.first < 0
                || p.second < 0
                || p.first >= iMax
                || p.second >= jMax) continue;
                if(grid[i][j] >= grid[p.first][p.second]){
                    lowPoint = false;
                    break;
                }
            }
            if(lowPoint){
                ans += grid[i][j] - '0' + 1;
            }
        }
    }
    cout << ans << '\n';
}