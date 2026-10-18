// Maximise the Profit by selecting the job with max profit but after one job is done next job should be of more deadline then previous one.

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2) {
    return p1.second > p2.second;
}

int max_profit_jobs (vector<pair<int,int>> &jobs) {

    sort(jobs.begin(),jobs.end(),compare);      // Sort on the basis of max Profit

    int n = jobs.size();

    int max_profit = jobs[0].second;
    int safe_deadline = jobs[0].first;

    for(int i=1;i<n;i++) {
        if(jobs[i].first > safe_deadline) {
            max_profit += jobs[i].second;
            safe_deadline = jobs[i].first; 
        }
    }

    return max_profit;
}

int main () {

    vector<pair<int,int>> jobs = {{4,20},{1,10},{1,100},{1,30},{2,90}};

    cout << "Maximum Profit Is : " << max_profit_jobs(jobs) << endl;

    return 0;
    
}