// We have to chanage the currency with minimum number of coins this can be done by giving biggest value coin less then or equal to number.
// Coins are : 1,2,5,10,20,50,100,500,1000 traverse them from backwards from biggest note to smalllest notes.

#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};

    int n = coins.size()-1;
    int value = 1990;
    int min_coins = 0;

    vector<pair<int,int>> coins_used;

    for(int i=n;i>=0 && value > 0; i--) {
        if(value >= coins[i]) {
            int count = value/coins[i]; 

            min_coins += count;    // It will give number of coins.

            value = value%coins[i];   // It will put remainig value in value variable.

            coins_used.push_back({coins[i],count});
        }
    }

    cout << "Minimum Number of Coins : " << min_coins << endl << "Coins used are : ";
    
    for(auto coin : coins_used) {
        cout << coin.first << "x" << coin.second << ",";
    }

    return 0;
}