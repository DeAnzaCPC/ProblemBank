#include <bits/stdc++.h>
using namespace std;

const int ROW = 5, COL = 5;
vector<string> grid(ROW);

bool checkKnightPos(int r, int c){
    vector< pair<int,int> > jump = {
        {r-2, c+1},
        {r-2, c-1},
        {r-1, c+2},
        {r-1, c-2},
        {r+1, c+2},
        {r+1, c-2},
        {r+2, c+1},
        {r+2, c-1}
    };
    for(pair<int,int> p:jump){
        if(p.first < 0 
        || p.second < 0
        || p.first >= ROW 
        || p.second >= COL) continue;
        if(grid[p.first][p.second] == 'k') return true;
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int r = 0; r < ROW; r++){
        cin >> grid[r];
    }
    bool ok = true;
    int knight_count = 0;
    for(int r = 0; r < ROW; r++){
        for(int c = 0; c < COL; c++){
            if(grid[r][c] == 'k'){
                knight_count++;
                if( checkKnightPos(r, c) ) {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) break;
    }
    if(knight_count != 9) ok = false;
    cout << (ok?"valid\n":"invalid\n");
}