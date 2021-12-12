#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> grid;
    string line;
    while(getline(cin, line)) grid.push_back(line);
    int iMax = grid.size(), jMax = grid[0].size();
    vector<vector<bool>> used(iMax, vector<bool>(jMax));
    vector<int> basinSizes;
    for(int i = 0; i < iMax; i++){
        for(int j = 0; j < jMax; j++){
            if(used[i][j] || grid[i][j] == '9') continue;
            int currBasin = 1;
            deque<pair<int,int>> q;
            q.push_back({i, j});
            used[i][j] = true;
            while(!q.empty()){
                pair<int,int> curr = q.front();
                q.pop_front();
                vector<pair<int,int>> directions = {
                    {curr.first - 1, curr.second},
                    {curr.first + 1, curr.second},
                    {curr.first, curr.second - 1},
                    {curr.first, curr.second + 1}
                };
                for(auto p : directions){
                    if(p.first < 0
                    || p.second < 0
                    || p.first >= iMax
                    || p.second >= jMax) continue;
                    if(used[p.first][p.second]
                    || grid[p.first][p.second] == '9') continue;
                    used[p.first][p.second] = true;
                    currBasin++;
                    q.push_back(p);
                }
            }
            basinSizes.push_back(currBasin);
        }
    }
    sort(basinSizes.rbegin(), basinSizes.rend());
    cout << (long long)basinSizes[0] * basinSizes[1] * basinSizes[2] << '\n';
}