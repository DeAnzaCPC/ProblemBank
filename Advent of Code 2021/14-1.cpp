#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in2.txt","r",stdin); freopen("out.txt","w",stdout);
    string start_str;
    getline(cin, start_str);
    map<pair<char,char>, char> m;
    string pair_str, arrow;
    char add_char;
    while(cin >> pair_str >> arrow >> add_char){
        m[{pair_str[0], pair_str[1]}] = add_char;
    }

    map<pair<char, char>, long long> prevString;
    for(int i = 0; i < start_str.size() - 1; i++){
        prevString[{start_str[i], start_str[i + 1]}]++;
    }

    const int endStep = 40;
    for(int step = 0; step < endStep; step++){
        map<pair<char, char>, long long> nextString;
        for(auto [p, cnt] : prevString){
            if(m.count(p)){
                nextString[{p.first, m[p]}] += cnt;
                nextString[{m[p], p.second}] += cnt;
            } else {
                nextString[p] += cnt;
            }
        }
        nextString.swap(prevString);
    }
    
    map<char, long long> char_cnt;
    for(auto [p, cnt] : prevString){
        char_cnt[p.first] += cnt;
        char_cnt[p.second] += cnt;
    }
    char_cnt[start_str.front()]++;
    char_cnt[start_str.back()]++;

    long long maxChar = 0, minChar = 1e18;
    for(auto [c, cnt] : char_cnt){
        cnt /= 2;
        maxChar = max(maxChar, cnt);
        minChar = min(minChar, cnt);
    }

    cout << maxChar << ' ' << minChar << '\n';
    cout << maxChar - minChar << '\n';
}