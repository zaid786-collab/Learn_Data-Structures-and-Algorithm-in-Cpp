// 1. Calculate value/weight
// 2. Sort descending
// 3. If item fits → take full
// 4. Otherwise → take fraction
// 5. Stop when capacity = 0


#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2)
{
    return p1.first > p2.first;      // Sorting Ration in Descending Order.
}

int fractionalKnapsack(vector<int> val,vector<int> wt,int W) {
    int n = val.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0));

    for(int i=0;i<n;i++) {
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(), compare);

    int ans = 0;

    for(int i=0;i<n;i++) {
        int index = ratio[i].second;   // Gives index of wt and val

        if(wt[index] < W) {
            ans += val[index];
            W -= wt[index];
        }else {
            ans += ratio[i].first * W;
            W = 0;
            break;
        }
    }

    return ans;
}


int main () {
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;

    cout << "Max Value in Fractional Knapsack : " << fractionalKnapsack(val,wt,W) << endl;

    return 0;
}