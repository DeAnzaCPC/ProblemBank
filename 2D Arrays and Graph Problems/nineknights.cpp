#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<string> grid;
    string line;
    while(getline(cin, line)){
        grid.push_back(move(line));
    }

    // n always equals 5, but initialized dynamically for this example
    int n = grid.size(); 
    int knight_count = 0;
    bool valid = true;
    for(int i = 0; i < n && valid; i++){
        for(int j = 0; j < n && valid; j++){
            if(grid[i][j] == '.') continue;
            knight_count++;
            vector<pair<int,int>> directions = {
                {i - 2, j - 1},
                {i - 2, j + 1},
                {i - 1, j - 2},
                {i - 1, j + 2},
                {i + 1, j - 2},
                {i + 1, j + 2},
                {i + 2, j - 1},
                {i + 2, j + 1}
            };
            for(auto& [newI, newJ] : directions){
                if(newI < 0 
                || newJ < 0
                || newI >= n
                || newJ >= n) continue;
                if(grid[newI][newJ] == 'k'){
                    valid = false;
                    break;
                }
            }
        }
    }
    if(knight_count != 9) valid = false;
    cout << (valid ? "valid\n" : "invalid\n");
}