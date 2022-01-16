#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int rows, cols; cin >> rows >> cols;
    vector<string> grid(rows);
    for(string& s : grid) cin >> s;

    // alternatively, use a set to keep track of repeated coordinates
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int currI = 0, currJ = 0;
    int moves = 0;

    while(true){
        // cout << currI << ' ' << currJ << '\n';
        if(currI < 0
        || currJ < 0
        || currI >= rows
        || currJ >= cols){
            cout << "Out\n";
            return 0;
        }
        if(visited[currI][currJ]){
            cout << "Lost\n";
            return 0;
        }
        if(grid[currI][currJ] == 'T') break;

        visited[currI][currJ] = true;
        moves++;
        switch(grid[currI][currJ]){
            case 'N': 
                currI--;
                break;
            case 'S':
                currI++;
                break;
            case 'E':
                currJ++;
                break;
            case 'W':
                currJ--;
                break;
        }
    }
    cout << moves << '\n';
}