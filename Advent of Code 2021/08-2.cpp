#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> segments = {
    {0,1,2,4,5,6},
    {2,5},
    {0,2,3,4,6},
    {0,2,3,5,6},
    {1,2,3,5},
    {0,1,3,5,6},
    {0,1,3,4,5,6},
    {0,2,5},
    {0,1,2,3,4,5,6},
    {0,1,2,3,5,6}
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

    unordered_map<int,int> m;
    for(int i = 0; i < 10; i++){
        int sum = 0;
        for(int seg : segments[i]){
            sum += 1<<seg;
        }
        m[sum] = i;
    }

    int ans = 0;
    while(!cin.eof()){
        int curr = 0;
        vector<string> str_keys(10), str_code(4);
        for(string & s : str_keys) {
            cin >> s;
        }
        cin >> str_code[0]; // skip '|'
        for(string & s : str_code) {
            cin >> s;
        }

        vector<int> mapping(7);
        iota(mapping.begin(), mapping.end(), 0);
        do{
            bool ok = true;
            for(string s : str_keys){
                int sum = 0;
                for(char c : s){
                    sum += 1<<mapping[c - 'a'];
                }
                if(!m.count(sum)){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            for(string s : str_code){
                int sum = 0;
                for(char c : s){
                    sum += 1<<mapping[c - 'a'];
                }
                curr *= 10;
                curr += m[sum];
            }
            ans += curr;
            break;
        } while(next_permutation(mapping.begin(), mapping.end()));

    }
    cout << ans << '\n';
}