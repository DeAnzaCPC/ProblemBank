#include <bits/stdc++.h>
using namespace std;

int n, startVal;
map<string, vector<string>> adj;
map<string, int> str_val;
vector<vector<string>> ans;
vector<bool> used;

void dfs(vector<string>& pattern, bool& revisitedSmall){
    if(pattern.back() == "end"){
        ans.push_back(pattern);
        return;
    }
    if(adj[pattern.back()].size() == 0) return;
    for(string s : adj[pattern.back()]){
        bool small = false;
        if(used[str_val[s]]){
            if(revisitedSmall || s == "start"){
                continue;
            } else {
                small = true;
                revisitedSmall = true;
            }
        }
        bool isLower = false;
        if(s[0] >= 'a' && s[0] <= 'z') isLower = true;
        if(isLower) used[str_val[s]] = true;
        pattern.push_back(s);
        dfs(pattern, revisitedSmall);
        pattern.pop_back();
        if(small) revisitedSmall = false;
        else used[str_val[s]] = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    string line;
    while(getline(cin, line)){
        int dash = 0;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '-'){
                dash = i;
                break;
            }
        }
        string from = line.substr(0, dash);
        string to = line.substr(dash+1, line.size() - dash);
        // cout << from << ' ' << to << '\n';
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    n = adj.size();
    int cnt = 0;
    for(auto v : adj){
        str_val[v.first] = cnt++;
    }
    startVal = str_val["start"];
    vector<string> pattern;
    pattern.push_back("start");
    used.resize(n);
    used[startVal] = true;
    bool revisitedSmall = false;
    dfs(pattern, revisitedSmall);

    for(auto v : ans){
        for(int i = 0; i < v.size() - 1; i++){
            cout << v[i] << ',';
        }
        cout << v.back() << '\n';
    }
    cout << ans.size() << '\n';
}