#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in2.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<int> nums;
    int next;
    while(cin >> next){
        nums.push_back(next);
    }
    int n = nums.size(), ans = 0;
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1]) ans++;
    }
    cout << ans << '\n';
}