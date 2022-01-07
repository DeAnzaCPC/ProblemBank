#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // n*n matrix

        // swap matrix from top to bottom
        reverse(matrix.begin(), matrix.end());

        // swap matrix along diagonal
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void rotateNotInPlace(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> new_matrix(n, vector<int>(n));
        for(int j = 0; j < n; j++){
            for(int i = n - 1; i >= 0; i--){
                new_matrix[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = move(new_matrix);
    }
};

void print2DVector(const vector<vector<int>>& grid) {
    cout << '[';
    for(vector<int> v : grid){
        cout << '[';
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            if(i != v.size() - 1) cout << ',';
        }
        cout << ']';
    }
    cout << "]\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution solve;

    vector<vector<int>> ex1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    print2DVector(ex1);
    solve.rotate(ex1);
    print2DVector(ex1);
    
    vector<vector<int>> ex2 = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    print2DVector(ex2);
    solve.rotate(ex2);
    print2DVector(ex2);
}