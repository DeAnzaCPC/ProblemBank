#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    unordered_map<char, int> score = {
        {')', 3},
        {']', 57},
        {'}', 1197},
        {'>', 25137}
    };
    unordered_set<char> open = {
        '(', '[', '{', '<'
    };
    unordered_map<char, char> match = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'<', '>'}
    };
    
    int ans = 0;
    string line;
    while(cin >> line){
        deque<char> st;
        bool corrupt = false;
        for(char c : line){
            if(corrupt) break;
            if(open.count(c)){
                st.push_front(c);
            } else {
                if(!st.empty()){
                    char get = st.front();
                    st.pop_front();
                    if(c != match[get]){
                        ans += score[c];
                        corrupt = true;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}