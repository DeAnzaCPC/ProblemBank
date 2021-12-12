#include <bits/stdc++.h>
using namespace std;

bool checkWin(const vector<vector<bool>>& board) {
    for(int row = 0; row < 5; row++){
        bool ok = true;
        for(int col = 0; col < 5 && ok; col++){
            if(!board[row][col]) ok = false;
        }
        if(ok) return true;
    }
    for(int col = 0; col < 5; col++){
        bool ok = true;
        for(int row = 0; row < 5 && ok; row++){
            if(!board[row][col]) ok = false;
        }
        if(ok) return true;
    }

    bool ok = true;
    for(int col = 0; col < 5 && ok; col++){
        if(!board[col][col]) ok = false;
    }
    if(ok) return true;

    for(int col = 0; col < 5; col++){
        int row = 4 - col;
        if(!board[row][col]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    
    vector<int> bingoNums;
    string values; 
    getline(cin, values);
    int currStart = 0;
    for(int i = 0; i < values.size(); i++){
        if(values[i] != ',') continue;
        string nextVal = values.substr(currStart, i - currStart);
        currStart = i + 1;
        bingoNums.push_back(stoi(nextVal));
    }
    string nextVal = values.substr(currStart);
    bingoNums.push_back(stoi(nextVal));

    int slowestWin = -1, score;
    vector<vector<int>> board(5, vector<int>(5));
    while(!cin.eof()){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> board[i][j];
            }
        }
        vector<vector<bool>> used(5, vector<bool>(5));
        bool win = false;
        int winValue, winTime;
        for(int i = 0; i < bingoNums.size() && !win; i++){
            for(int r = 0; r < 5 && !win; r++){
                for(int c = 0; c < 5; c++){
                    if(board[r][c] == bingoNums[i]) {
                        used[r][c] = true;
                        if(checkWin(used)) {
                            win = true;
                            winValue = bingoNums[i];
                            winTime = i;
                            break;
                        }
                    }
                }
            }
        }
        if(win){
            if(winTime <= slowestWin) continue;
            slowestWin = winTime;
            int total = 0;
            for(int r = 0; r < 5; r++){
                for(int c = 0; c < 5; c++){
                    if(used[r][c]) continue;
                    total += board[r][c];
                }
            }
            score = total * winValue;
        }
    }
    cout << score << '\n';
}