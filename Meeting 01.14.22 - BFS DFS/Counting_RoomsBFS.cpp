#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(string& s : grid) cin >> s;
    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') continue;
            rooms++;
            grid[i][j] = '#';
            
            queue<pair<int,int>> q;
            q.push({i,j});

            while(!q.empty()){
                auto [f, s] = q.front();
                q.pop();

                vector<pair<int,int>> directions = {
                    {f - 1, s},
                    {f + 1, s},
                    {f, s - 1},
                    {f, s + 1}
                };
                for(auto [nextI, nextJ] : directions){
                    if(nextI < 0
                    || nextJ < 0
                    || nextI >= n
                    || nextJ >= m) continue;
                    if(grid[nextI][nextJ] == '#') continue;
                    grid[nextI][nextJ] = '#';
                    q.push({nextI, nextJ});
                }
            }
        }
    }

    cout << rooms << '\n';
}