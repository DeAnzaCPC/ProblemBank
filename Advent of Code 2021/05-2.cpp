#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    const int mapSize = 1000;
    vector<vector<int>> vent_count(mapSize, vector<int>(mapSize));
    while(!cin.eof()){
        string line;
        getline(cin, line);
        vector<int> nums;
        string currString = "";
        for(char c : line){
            if(c >= '0' && c <= '9') currString.push_back(c);
            else if(currString.size() > 0) {
                nums.push_back(stoi(currString));
                currString = "";
            }
        }
        if(currString.size() > 0) nums.push_back(stoi(currString));
        

        if(nums[0] == nums[2]){
            // row1 == row2
            int col = nums[0];
            for(int row = min(nums[1], nums[3]); row <= max(nums[1], nums[3]); row++){
                vent_count[row][col]++;
            }
        } else if(nums[1] == nums[3]){
            // col1 == col2
            int row = nums[1];
            for(int col = min(nums[0], nums[2]); col <= max(nums[0], nums[2]); col++){
                vent_count[row][col]++;
            }
        } else {
            // start = nums 1, 0
            // end = nums 3, 2
            int startRow, startCol, endRow, endCol;
            if(nums[1] < nums[3]){
                startRow = nums[1];
                endRow = nums[3];
                startCol = nums[0];
                endCol = nums[2];
            } else {
                startRow = nums[3];
                endRow = nums[1];
                startCol = nums[2];
                endCol = nums[0];
            }
            if(startCol < endCol){
                int col = startCol;
                for(int row = startRow; row <= endRow; row++, col++){
                    vent_count[row][col]++;
                }
            } else {
                int col = startCol; 
                for(int row = startRow; row <= endRow; row++, col--){
                    vent_count[row][col]++;
                }
            }
        }
    }

    int ans = 0;
    for(int r = 0; r < mapSize; r++){
        for(int c = 0; c < mapSize; c++){
            // cout << vent_count[r][c] << ' ';
            if(vent_count[r][c] > 1) ans++;
        }
        // cout << '\n';
    }
    cout << ans << '\n';
}