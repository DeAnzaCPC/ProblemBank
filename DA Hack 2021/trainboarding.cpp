#include <bits/stdc++.h>
using namespace std;

int n, l, p;

int distToCar(int location, int car){
    return abs(location - (car*l + l/2));
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> l >> p;
    vector<int> passengers(n, 0);
    int farthest = 0;
    for(int i = 0; i < p; i++){
        int location; cin >> location;
        int car = min(location / l, n-1);
        passengers[car]++;
        farthest = max(farthest, distToCar(location, car));
    }
    int maxPassengers = *max_element(passengers.begin(), passengers.end());
    cout << farthest << '\n' << maxPassengers << '\n';
}