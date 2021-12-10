#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<vector<int>> vent_count(1000, vector<int>(1000));
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
            int row = nums[0];
            for(int col = min(nums[1], nums[3]); col <= max(nums[1], nums[3]); col++){
                vent_count[row][col]++;
            }
        } else if(nums[1] == nums[3]){
            // col1 == col2
            int col = nums[1];
            for(int row = min(nums[0], nums[2]); row <= max(nums[0], nums[2]); row++){
                vent_count[row][col]++;
            }
        }
    }

    int ans = 0;
    for(int r = 0; r < 1000; r++){
        for(int c = 0; c < 1000; c++){
            if(vent_count[r][c] > 1) ans++;
        }
    }
    cout << ans << '\n';
}