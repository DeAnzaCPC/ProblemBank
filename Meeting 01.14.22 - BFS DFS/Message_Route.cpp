#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> prevs(n, -1);
    queue<int> q;
    q.push(0);
    prevs[0] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == n - 1) break;
        for(int next : adj[curr]){
            if(prevs[next] != -1) continue;
            prevs[next] = curr;
            q.push(next);
        }
    }

    if(prevs[n - 1] != -1){
        vector<int> path;
        int curr = n - 1;
        path.push_back(curr);
        while(curr != 0){
            curr = prevs[curr];
            path.push_back(curr);
        }
        cout << path.size() << '\n';
        for(int i = path.size() - 1; i > 0; i--){
            cout << path[i] + 1 << ' ';
        }
        cout << path[0] + 1 << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}