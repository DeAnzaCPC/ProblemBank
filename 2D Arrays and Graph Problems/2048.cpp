#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
void left();
void up();
void right();
void down();

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    grid.resize(4, vector<int>(4));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> grid[i][j];
        }
    }
    // 0123 = left, up, right, down
    int direction; cin >> direction;
    // 2 0 0 2 -> 4 0 0 0
    // 2 2 4 4 -> 4 8 0 0
    // 4 2 2 4 -> 4 4 4 0
    switch(direction){
        case 0: left(); break;
        case 1: up(); break;
        case 2: right(); break;
        case 3: down(); break;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

void left(){
    for(int row = 0; row < 4; row++){
        // combine with closest number right
        for(int i = 0; i < 3; i++){
            if(grid[row][i] == 0) continue;
            for(int j = i+1; j < 4; j++){
                if(grid[row][j] == 0) continue;
                if(grid[row][i] == grid[row][j]){
                    grid[row][i] *= 2;
                    grid[row][j] = 0;
                }
                break;
            }
        }
        // move numbers to the left if current number is 0
        for(int i = 0; i < 3; i++){
            if(grid[row][i] == 0){
                for(int j = i+1; j < 4; j++){
                    if(grid[row][j]){
                        grid[row][i] = grid[row][j];
                        grid[row][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void up(){
    for(int col = 0; col < 4; col++){
        for(int i = 0; i < 3; i++){
            if(grid[i][col] == 0) continue;
            for(int j = i+1; j < 4; j++){
                if(grid[j][col] == 0) continue;
                if(grid[i][col] == grid[j][col]){
                    grid[i][col] *= 2;
                    grid[j][col] = 0;
                }
                break;
            }
        }
        for(int i = 0; i < 3; i++){
            if(grid[i][col] == 0){
                for(int j = i+1; j < 4; j++){
                    if(grid[j][col]){
                        grid[i][col] = grid[j][col];
                        grid[j][col] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void down(){
    for(int col = 0; col < 4; col++){
        for(int i = 3; i > 0; i--){
            if(grid[i][col] == 0) continue;
            for(int j = i-1; j >= 0; j--){
                if(grid[j][col] == 0) continue;
                if(grid[i][col] == grid[j][col]){
                    grid[i][col] *= 2;
                    grid[j][col] = 0;
                }
                break;
            }
        }
        for(int i = 3; i > 0; i--){
            if(grid[i][col] == 0){
                for(int j = i-1; j >= 0; j--){
                    if(grid[j][col]){
                        grid[i][col] = grid[j][col];
                        grid[j][col] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void right(){
    for(int row = 0; row < 4; row++){
        for(int i = 3; i > 0; i--){
            if(grid[row][i] == 0) continue;
            for(int j = i-1; j >= 0; j--){
                if(grid[row][j] == 0) continue;
                if(grid[row][i] == grid[row][j]){
                    grid[row][i] *= 2;
                    grid[row][j] = 0;
                }
                break;
            }
        }
        for(int i = 3; i > 0; i--){
            if(grid[row][i] == 0){
                for(int j = i-1; j >= 0; j--){
                    if(grid[row][j]){
                        grid[row][i] = grid[row][j];
                        grid[row][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}