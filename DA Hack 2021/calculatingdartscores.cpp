#include <bits/stdc++.h>
using namespace std;

void printMultiplier(int multiplier){
    switch(multiplier){
        case 1: cout << "single "; break;
        case 2: cout << "double "; break;
        case 3: cout << "triple "; break;
        default: return;
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int target; cin >> target;
    for(int mult1 = 1; mult1 <= 3; mult1++){
        for(int i = 0; i <= 20; i++){
            for(int mult2 = 1; mult2 <= 3; mult2++){
                for(int j = 0; j <= 20; j++){
                    for(int mult3 = 1; mult3 <= 3; mult3++){
                        for(int k = 0; k <= 20; k++){
                            if(mult1*i + mult2*j + mult3*k == target){
                                if(i){
                                    printMultiplier(mult1);
                                    cout << i << '\n';
                                }
                                if(j){
                                    printMultiplier(mult2);
                                    cout << j << '\n';
                                }
                                if(k){
                                    printMultiplier(mult3);
                                    cout << k << '\n';
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "impossible\n";
}