#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(string& s : grid) cin >> s;
    pair<int,int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<pair<int,int>>> prevs(n, vector<pair<int,int>>(m));
    vector<vector<char>> direction(n, vector<char>(m));
    vector<char> dir = {
        'U', 'D', 'L', 'R'
    };

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool ok = false;
    while(!q.empty() && !ok){
        auto curr = q.front();
        auto[i, j] = curr;
        q.pop();

        vector<pair<int,int>> next_dir = {
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        for(int d = 0; d < 4; d++){
            auto [nextI, nextJ] = next_dir[d];
            if(nextI < 0
            || nextJ < 0
            || nextI >= n
            || nextJ >= m) continue;
            if(grid[nextI][nextJ] == '#') continue;
            if(visited[nextI][nextJ]) continue;
            
            visited[nextI][nextJ] = true;
            direction[nextI][nextJ] = dir[d];
            prevs[nextI][nextJ] = curr;
            q.push(next_dir[d]);
            if(next_dir[d] == end) {
                ok = true;
                break;
            }
        }
    }

    if(ok){
        pair<int,int> curr = end;
        string path = "";
        while(curr != start){
            path.push_back(direction[curr.first][curr.second]);
            curr = prevs[curr.first][curr.second];
        }
        cout << "YES\n" << path.size() << '\n';
        reverse(path.begin(), path.end());
        cout << path << '\n';
    } else {
        cout << "NO\n";
    }
}