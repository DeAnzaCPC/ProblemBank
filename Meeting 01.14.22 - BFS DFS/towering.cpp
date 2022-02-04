#include <bits/stdc++.h>
using namespace std;
int h1, h2; 
vector<int> heights(6);

bool cmp(int a, int b){
    return a > b;
}

void dfs(vector<int>& pattern, vector<bool>& used){
    if(pattern.size() < 6){
        for(int i = 0; i < 6; i++){
            if(used[i]) continue;
            used[i] = true;
            pattern.push_back(heights[i]);
            dfs(pattern, used);
            used[i] = false;
            pattern.pop_back();
        }
        return;
    }

    int sum1 = accumulate(pattern.begin(), pattern.begin()+3, 0);
    int sum2 = accumulate(pattern.begin()+3, pattern.end(), 0);
    if(sum1 == h1 && sum2 == h2){
        sort(pattern.begin(), pattern.begin()+3, cmp);
        sort(pattern.begin()+3, pattern.end(), cmp);
        for(int i : pattern){
            cout << i << ' ';
        }
        cout << '\n';
        exit(0);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for(int& i : heights) cin >> i;
    cin >> h1 >> h2;

    vector<bool> used(6);
    vector<int> pattern;
    dfs(pattern, used);
}