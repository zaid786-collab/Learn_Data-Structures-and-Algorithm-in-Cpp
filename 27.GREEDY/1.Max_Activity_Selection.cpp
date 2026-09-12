// Classsical Question asked in Interviews very frequesntly, here we have to calculate the maxium number of activities which a person can perform.
// here starting and ending time of each activity is alreadfy given to uss.
// KEY LOGIC : 1. Sort ending time of task[here it is already given], 2. Count all the non-overlapping tasks.[first.endingtime <= second.startingtime].

#include<bits/stdc++.h>
using namespace std;

int maxactivity(vector<int> start,vector<int> end) {
    int n = start.size();
    int count = 1;
    int currendtime = end[0];

    for(int i=1;i<n;i++) {
        if(currendtime <= start[i]) {
            count++;
            currendtime = end[i];
        }
    }

    return count;
}

int main () {
    vector<int> startingtime = {1,3,0,5,8,5};
    vector<int> endingtime = {2,4,6,7,9,9};

    cout << "Maximum Activity At a Time : "<<maxactivity(startingtime,endingtime);
    return 0;
}