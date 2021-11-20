#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    stack<int> ans;
    ans.push(0);
    for(int i = 0; i < k; i++){
        string command; cin >> command;
        if(command == "undo"){
            int undo_count; cin >> undo_count;
            while(undo_count--){
                ans.pop();
            }
            continue;
        }
        int c = stoi(command);
        int curr = ans.top();
        curr = (curr+c)%n;
        while(curr<0){
            curr+=n;
        }
        ans.push(curr);
        // cout << curr << endl;
    }
    cout << ans.top() << endl;
}