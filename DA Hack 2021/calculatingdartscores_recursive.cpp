#include <bits/stdc++.h>
using namespace std;

bool found = false;

void printMultiplier(int multiplier){
    switch(multiplier){
        case 1: cout << "single "; break;
        case 2: cout << "double "; break;
        case 3: cout << "triple "; break;
        default: return;
    }
}

void dfs(vector<int>&multipliers, vector<int>&scores, int target){
    if(found) return;
    if(scores.size()<3){
        for(int mult = 1; mult <= 3; mult++){
            for(int score = 0; score <= 20; score++){
                multipliers.push_back(mult);
                scores.push_back(score);

                dfs(multipliers, scores, target);

                multipliers.pop_back();
                scores.pop_back();
            }
        }
        return;
    }
    int totalScore = 0;
    for(int i = 0; i < 3; i++){
        totalScore += multipliers[i]*scores[i];
    }
    if(totalScore == target){
        found = true;
        for(int i = 0; i < 3; i++){
            if(scores[i]){
                printMultiplier(multipliers[i]);
                cout << scores[i] << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int target; cin >> target;
    vector<int>multipliers, scores;
    dfs(multipliers, scores, target);
    if(!found){
        cout << "impossible\n";
    }
}