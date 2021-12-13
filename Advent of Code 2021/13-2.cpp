#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    set<pair<int,int>> s;
    string line;
    getline(cin, line);
    do{
        int comma = line.find(',');
        string num_str1 = line.substr(0, comma);
        string num_str2 = line.substr(comma + 1);
        int num1 = stoi(num_str1);
        int num2 = stoi(num_str2);
        s.insert({num1, num2});
        getline(cin, line);
    } while(line != "");

    vector<pair<int,bool>> folds;
    while(getline(cin, line)){
        char xy = line[11];
        string foldNum_str = line.substr(13);
        int foldVal = stoi(foldNum_str);
        pair<int,bool> nextFold;
        nextFold.first = foldVal;
        nextFold.second = (xy == 'x');
        folds.push_back(nextFold);
    }

    for(pair<int,bool> fold : folds){
        set<pair<int,int>> newSet;
        for(auto p : s){
            pair<int,int> newPair = p;
            if(fold.second && p.first >= fold.first){
                newPair.first = fold.first - (p.first - fold.first);
            } else if(!fold.second && p.second >= fold.first){
                newPair.second = fold.first - (p.second - fold.first);
            }
            newSet.insert(newPair);
        }
        s.swap(newSet);
    }

    int maxX = 0, maxY = 0;
    for(auto p : s) {
        maxX = max(maxX, p.first);
        maxY = max(maxY, p.second);
    }
    
    for(int y = 0; y <= maxY; y++){
        for(int x = 0; x <= maxX; x++){
            if(s.count({x, y})) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }

    
}