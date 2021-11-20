#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n1, n2;
    while(true){
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0) break;
        // cout << n1 << ' ' << digitSum(n1) << '\n';
        // cout << n2 << ' ' << digitSum(n2) << '\n';
        // cout << "\n\n";
        int carries = digitSum(n1) + digitSum(n2) - digitSum(n1+n2);
        carries /= 9;
        if(carries){
            if(carries == 1){
                cout << "1 carry operation.\n";
            } else {
                cout << carries << " carry operations.\n";
            }
        } else {
            cout << "No carry operation.\n";
        }
    }
}