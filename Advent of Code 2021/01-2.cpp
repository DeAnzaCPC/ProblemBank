#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<int> nums;
    int next;
    while(cin >> next){
        nums.push_back(next);
    }
    int n = nums.size(), ans = 0;
    for(int i = 0; i < n - 3; i++){
        if(nums[i + 3] > nums[i]) ans++;
    }
    cout << ans << '\n';
}