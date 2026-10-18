// To get max length of non-overlapping pairs by the concept of Activity Selection where starting.ith > ending.(ith-1). 

#include<bits/stdc++.h>
using namespace std;

bool compare (pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int maxchainlength(vector<pair<int,int>> pairs) {
    sort(pairs.begin(),pairs.end(),compare);

    int chainlength = 1;
    int curr_end = pairs[0].second;

    int i = 1;
    while(i < 5) {
        if(pairs[i].first > curr_end) {
            chainlength++;
            curr_end = pairs[i].second;
        }
        i++;
    }

    return chainlength;
} 

int main () {
    int n = 5;
    vector<pair<int,int>> pairs(n,make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(25,26);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    cout << "Maximum Size of Chain of Length is : " << maxchainlength(pairs) << endl;

    return 0;
}