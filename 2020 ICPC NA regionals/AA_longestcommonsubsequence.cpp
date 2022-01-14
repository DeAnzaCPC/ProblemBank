#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<vector<int>> cnt(K, vector<int>(K));
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < K; j++){
            for(int k = j + 1; k < K; k++){
                cnt[s[j] - 'A'][s[k] - 'A']++;
            }
        }
    }

    vector<vector<int>> adj(K), back(K);
    vector<int> in_degree(K), dist(K, -INF);
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            if(cnt[i][j] == N){
                adj[i].push_back(j);
                back[j].push_back(i);
                in_degree[j]++;
            }
        }
    }

    queue<int> q;
    for(int i = 0; i < K; i++){
        if(in_degree[i] == 0){
            q.push(i);
            dist[i] = 1;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int next : adj[node]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }

        int mx = -INF, mxnode = -1;
        for(int prev : back[node]){
            if(dist[prev] + 1 > mx){
                mx = dist[prev] + 1;
                mxnode = prev;
            }
        }
        dist[node] = max(dist[node], mx);
    }

    cout << *max_element(dist.begin(), dist.end()) << '\n';
}