#include <bits/stdc++.h>
using namespace std;

int small_n, big_n;

/*
    regions:
    s 0 1 2 3
    0 1 2 3 4
    1 2 3 4 5
    2 3 4 5 6
    3 4 5 6 7
    
    0 1 2 3 4
    1 
    2 
    3
    4

    0: small_n to 2*small_n

*/
const vector< vector< pair<int,int> > > regionCoord = {
    {{0, 1}, {1, 0}},
    {{0, 2}, {1, 1}, {2, 0}},
    {{0, 3}, {1, 2}, {2, 1}, {3, 0}},
    {{0, 4}, {1, 3}, {2, 2}, {3, 1}, {4, 0}},
    {{1, 4}, {2, 3}, {3, 2}, {4, 1}},
    {{2, 4}, {3, 3}, {4, 2}},
    {{3, 4}, {4, 3}},
    {{4,4}}
};

void fillRegions(int region, vector<vector<int>>& nextCost, vector<vector<int>>& cost){
    for(auto [multI, multJ] : regionCoord[region]){
        int startI = small_n * multI;
        int startJ = small_n * multJ;
        for(int i = startI; i < startI + small_n; i++){
            for(int j = startJ; j < startJ + small_n; j++){
                cost[i][j] = nextCost[i - startI][j - startJ];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> grid;
    string line;
    while(getline(cin, line)) grid.push_back(line);
    small_n = grid.size();
    big_n = small_n * 5;
    vector<vector<int>> cost(big_n, vector<int>(big_n));
    vector<vector<int>> prevCost(small_n, vector<int>(small_n));
    for(int i = 0; i < small_n; i++){
        for(int j = 0; j < small_n; j++){
            cost[i][j] = grid[i][j] - '0';
            prevCost[i][j] = cost[i][j];
        }
    }

    /*
        regions:
        s 0 1 2 3
        0 1 2 3 4
        1 2 3 4 5
        2 3 4 5 6
        3 4 5 6 7
    */
    for(int region = 0; region < 8; region++){
        vector<vector<int>> nextCost(small_n, vector<int>(small_n));
        for(int i = 0; i < small_n; i++){
            for(int j = 0; j < small_n; j++){
                nextCost[i][j] = prevCost[i][j] + 1;
                if(nextCost[i][j] > 9) nextCost[i][j] = 1;
            }
        }
        fillRegions(region, nextCost, cost);
        nextCost.swap(prevCost);
    }

    // for(int i = 0; i < big_n; i++){
    //     for(int j = 0; j < big_n; j++){
    //         cout << cost[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    const int INF = 1e9;
    vector<vector<int>> travel_cost(big_n, vector<int>(big_n, INF));
    travel_cost[0][0] = 0;
    set<pair<int, pair<int,int>>> pq;
    pq.insert(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()){
        auto currCoord = pq.begin()->second;
        pq.erase(pq.begin());
        vector<pair<int,int>> directions = {
            {currCoord.first - 1, currCoord.second},
            {currCoord.first + 1, currCoord.second},
            {currCoord.first, currCoord.second - 1},
            {currCoord.first, currCoord.second + 1}
        };
        for(auto& [next_i, next_j] : directions){
            if(next_i < 0
            || next_j < 0
            || next_i >= big_n
            || next_j >= big_n) continue;
            if(travel_cost[currCoord.first][currCoord.second] + cost[next_i][next_j] >= travel_cost[next_i][next_j]) continue;
            travel_cost[next_i][next_j] = travel_cost[currCoord.first][currCoord.second] + cost[next_i][next_j];
            pq.insert(make_pair(travel_cost[next_i][next_j], make_pair(next_i, next_j)));
        }
    }

    cout << travel_cost[big_n - 1][big_n - 1] << '\n';
}