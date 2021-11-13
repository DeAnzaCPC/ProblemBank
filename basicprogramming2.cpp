#include <bits/stdc++.h>
using namespace std;

void twoSum(int target, vector<int> & a){
    set<int> s;
    for(int i:a){
        if(s.count(target - i)){
            cout << "Yes\n";
            return;
        }
        s.insert(i);
    }
    cout << "No\n";
}

void findDuplicate(vector<int> & a){
    set<int> s;
    for(int i : a){
        if(s.count(i)){
            cout << "Contains duplicate\n";
            return;
        }
        s.insert(i);
    }
    cout << "Unique\n";
}

void findMode(int necQuantity, vector<int> & a){
    map<int,int> m;
    for(int i:a) m[i]++;
    int mode = -1;
    for(pair<int,int> p:m){
        if(p.second > necQuantity){
            mode = p.first;
        }
    }
    cout << mode << '\n';
}

void findMedian(vector<int> & a){
    sort(a.begin(), a.end());
    if(a.size()&1){
        cout << a[a.size()/2] << '\n';
    } else {
        cout << a[a.size()/2 - 1] << ' ' << a[a.size()/2] << '\n';
    }
}

void printRange(int minVal, int maxVal, vector<int> & a){
    sort(a.begin(), a.end());
    int start = lower_bound(a.begin(), a.end(), minVal) - a.begin();
    for(int i = start; i < a.size(); i++){
        if(a[i] > maxVal) break;
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    switch(t){
        case 1:
            twoSum(7777, a);
            break;
        case 2: 
            findDuplicate(a);
            break;
        case 3: 
            findMode(n/2, a);
            break;
        case 4: 
            findMedian(a);
            break;
        case 5: 
            printRange(100, 999, a);
            break;
    }
}