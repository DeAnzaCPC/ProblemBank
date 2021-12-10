#include <bits/stdc++.h>
using namespace std;

struct Node{
    int index, weight;
    bool operator< (const Node& n2) const {
        return this->weight > n2.weight;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int nodes, edges, queries, starting_node;
    const int INF = 1e9;
    while(true){
        cin >> nodes >> edges >> queries >> starting_node;
        if(nodes == 0) break;
        vector<vector<Node>> adj(nodes);
        for(int i = 0; i < edges; i++){
            int from, to, weight;
            cin >> from >> to >> weight;
            adj[from].push_back({to, weight});
        }

        // dijkstra's
        vector<int> dist(nodes, INF);
        dist[starting_node] = 0;
        
        priority_queue<Node> pq;
        pq.push({starting_node, 0});
        while(!pq.empty()){
            int currIdx = pq.top().index;
            pq.pop();
            for(Node n : adj[currIdx]){
                if(dist[currIdx] + n.weight < dist[n.index]){
                    dist[n.index] = dist[currIdx] + n.weight;
                    pq.push({n.index, dist[n.index]});
                }
            }
        }

        for(int i = 0; i < queries; i++){
            int to;
            cin >> to;
            if(dist[to] == INF){
                cout << "Impossible\n";
            } else {
                cout << dist[to] << '\n';
            }
        }
        cout << '\n';
    }
}