#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m; 
vector<string> grid;
vector<vector<int>> m_dist;

void m_bfs(vector<pair<int,int>>& monsters){
    queue<pair<pair<int,int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for(auto p : monsters){
        q.push({p, 0});
    }

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        auto [i, j] = curr.first;
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
            if(visited[nextI][nextJ]) continue;
            visited[nextI][nextJ] = true;
            if(curr.second + 1 > m_dist[nextI][nextJ]) continue;
            m_dist[nextI][nextJ] = curr.second + 1;
            q.push({{nextI, nextJ}, m_dist[nextI][nextJ]});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n);
    for(string& s : grid) cin >> s;

    vector<pair<int,int>> monsters;
    m_dist.resize(n, vector<int>(m, INF));
    pair<int,int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
                m_dist[i][j] = 0;
            } else if(grid[i][j] == 'A'){
                start = {i, j};
            }
        }
    }
    m_bfs(monsters);
    
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<pair<int,int>>> prevs(n, vector<pair<int,int>>(m));
    vector<vector<char>> prev_char(n, vector<char>(m));
    vector<char> dir = {
        'U', 'D', 'L', 'R'
    };
    bool ok = false;

    q.push(start);
    dist[start.first][start.second] = 0;
    visited[start.first][start.second] = true;

    while(!q.empty() && !ok){
        auto p = q.front();
        auto [i, j] = p;
        q.pop();
        vector<pair<int,int>> directions = {
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        for(int d = 0; d < 4; d++){
            auto [nextI, nextJ] = directions[d];
            if(nextI < 0
            || nextJ < 0
            || nextI >= n
            || nextJ >= m){
                ok = true;
                end = p;
                break;
            }
            if(grid[nextI][nextJ] == '#') continue;
            if(visited[nextI][nextJ]) continue;
            visited[nextI][nextJ] = true;
            if(dist[i][j] + 1 >= m_dist[nextI][nextJ]) continue;
            dist[nextI][nextJ] = dist[i][j] + 1;
            prevs[nextI][nextJ] = p;
            prev_char[nextI][nextJ] = dir[d];
            q.push(directions[d]);
        }
    }

    if(ok){
        pair<int,int> curr = end;
        string path = "";
        while(curr != start){
            path.push_back(prev_char[curr.first][curr.second]);
            curr = prevs[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size() << '\n' << path;
    } else {
        cout << "NO\n";
    }
}