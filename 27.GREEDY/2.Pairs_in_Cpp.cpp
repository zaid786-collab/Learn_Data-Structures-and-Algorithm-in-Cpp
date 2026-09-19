#include<bits/stdc++.h>
using namespace std;

int maxactivity(vector<int> start,vector<int> end) {
    int count = 1;
    int currentend = end[0];
    int n = start.size();

    for(int i=1;i<n;i++) {
        if(currentend <= start[i]) {
            count++;
            currentend = end[i];
        }
    }


    return count;
}

bool compare(pair<int,int> p1,pair<int,int> p2) {
    return p1.second < p2.second; // ascending order sorting
}

int main () {
    vector<pair<int,int>> activities(4, make_pair(0,0));
    activities[0] = make_pair(0,9);
    activities[1] = make_pair(1,2);
    activities[2] = make_pair(2,4);
    activities[3] = make_pair(3,18);

    for(int i=0;i<4;i++) {
        cout << "A" << i << " : " << activities[i].first << "," << activities[i].second << endl;
    }

    sort(activities.begin(),activities.end(), compare);

    cout << "--------Sorted----------" << endl;
    for(int i=0;i<4;i++) {
        cout << "A" << i << " : " << activities[i].first << "," << activities[i].second << endl;
    }

    return 0;
}