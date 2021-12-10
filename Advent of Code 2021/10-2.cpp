#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    unordered_map<char, int> score = {
        {')', 1},
        {']', 2},
        {'}', 3},
        {'>', 4}
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
    
    vector<long long> scores;
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
                        corrupt = true;
                    }
                } else {
                    corrupt = true;
                }
            }
        }
        if(corrupt) continue;
        long long currScore = 0;
        while(!st.empty()){
            char needMatch = st.front();
            st.pop_front();
            char needed = match[needMatch];
            currScore *= 5;
            currScore += score[needed];
        }
        scores.push_back(currScore);
    }
    sort(scores.begin(), scores.end());
    cout << scores.size() << '\n';
    cout << scores[scores.size()/2] << '\n';
}