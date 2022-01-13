#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int k, r;
    cin >> k >> r;
    vector<int> ingredient(k);
    for(int& i : ingredient) cin >> i;
    vector<vector<int>> recipe(r, vector<int>(k));
    vector<int> price(r);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < k; j++){
            cin >> recipe[i][j];
        }
        cin >> price[i];
    }

    int maxSales = 0;
    for(int i = 0; i < r; i++){
        int minIngredient = 1e9;
        for(int j = 0; j < k; j++){
            if(recipe[i][j] == 0) continue;
            int currServings = ingredient[j] / recipe[i][j];
            minIngredient = min(minIngredient, currServings);
        }
        int currSales = minIngredient * price[i];
        maxSales = max(maxSales, currSales);
    }
    cout << maxSales << '\n';
}