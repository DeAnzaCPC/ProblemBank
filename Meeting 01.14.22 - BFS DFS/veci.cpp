#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> ans;

void dfs(string& t, vector<bool>& used){
    if(t.size() < n){
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            used[i] = true;
            t.push_back(s[i]);

            dfs(t, used);

            used[i] = false;
            t.pop_back();
        }
        return;
    }
    if(t > s){
        ans.push_back(t);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    n = s.size();

    vector<bool> used(n);
    string t = "";
    dfs(t, used);

    sort(ans.begin(), ans.end());
    if(ans.size()){
        cout << ans[0] << '\n';
    } else {
        cout << "0\n";
    }
}