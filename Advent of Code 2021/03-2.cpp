#include <bits/stdc++.h>
using namespace std;

string oxygenRating(vector<string> numbers){
    vector<string> nextNumbers;
    int digit = 0;
    while(numbers.size() > 1){
        nextNumbers.clear();
        int countOne = 0;
        for(string s : numbers){
            if(s[digit] == '1') countOne++;
        }
        if(countOne * 2 >= numbers.size()){
            for(string s : numbers){
                if(s[digit] == '1') nextNumbers.push_back(s);
            }
        } else {
            for(string s : numbers){
                if(s[digit] == '0') nextNumbers.push_back(s);
            }
        }
        numbers.swap(nextNumbers);
        digit++;
    }
    return numbers[0];
}

string co2Rating(vector<string> numbers){
    vector<string> nextNumbers;
    int digit = 0;
    while(numbers.size() > 1){
        nextNumbers.clear();
        int countOne = 0;
        for(string s : numbers){
            if(s[digit] == '1') countOne++;
        }
        if(countOne * 2 >= numbers.size()){
            for(string s : numbers){
                if(s[digit] == '0') nextNumbers.push_back(s);
            }
        } else {
            for(string s : numbers){
                if(s[digit] == '1') nextNumbers.push_back(s);
            }
        }
        numbers.swap(nextNumbers);
        digit++;
    }
    return numbers[0];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> numbers;
    string s;
    while(cin >> s){
        numbers.push_back(s);
    }

    string oxy = oxygenRating(numbers);
    int oxygen = 0;
    int n = oxy.size();
    for(int i = 0; i < n; i++){
        int complement = n - 1 - i; 
        if(oxy[i] == '1') oxygen += (1 << complement);
    }

    string co2 = co2Rating(numbers);
    int co2val = 0;
    for(int i = 0; i < n; i++){
        int complement = n - 1 - i;
        if(co2[i] == '1') co2val += (1 << complement);
    }
    cout << oxygen * co2val << '\n';
}