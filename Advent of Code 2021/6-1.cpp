#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<long long> fish(9);
    string line;
    getline(cin, line);
    int currIdx = 0;
    for(int i = 1; i < line.size(); i++){
        if(line[i] == ','){
            fish[ stoi( line.substr(currIdx, i - currIdx) ) ]++;
            currIdx = i + 1;
        }
    }
    fish[ stoi( line.substr(currIdx) ) ]++;
    
    const int lastDay = 256;
    for(int day = 1; day <= lastDay; day++){
        vector<long long> nextFish(9);
        nextFish[8] = fish[0];
        nextFish[6] = fish[0];
        for(int fish_timer = 1; fish_timer < 9; fish_timer++){
            nextFish[fish_timer - 1] += fish[fish_timer];
        }
        fish.swap(nextFish);
    }

    cout << accumulate(fish.begin(), fish.end(), 0ll) << '\n';
}