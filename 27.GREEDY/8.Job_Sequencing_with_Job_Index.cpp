// Maximise the Profit by selecting the job with max profit but after one job is done next job should be of more deadline then previous one and also mention the sequence of jobs done.

#include<bits/stdc++.h>
using namespace std;

class Job {
public:
    int index;
    int deadline;
    int profit;

    Job(int index,int deadline,int profit) {
        this->index = index;
        this->deadline = deadline;
        this->profit = profit;
    }
};  


int max_profit_jobs (vector<pair<int,int>> &pairs) {
    int n = pairs.size();
    vector<Job> jobs;         // Vector of Objects of Job Class.

    for(int i=0;i<n;i++) {
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }

    sort(jobs.begin(),jobs.end(), [](Job &a, Job &b) {   // Capture list[] and lambda function[Temperory Function for one time use].

        return a.profit > b.profit;

    });  // descending oder on the basis of profit

    int max_profit = jobs[0].profit;
    int safe_deadline = jobs[0].deadline;

    cout << jobs[0].index << " ";

    for(int i=1;i<n;i++) {
        if(jobs[i].deadline >= safe_deadline) {
            cout << jobs[i].index << " ";
            max_profit += jobs[i].profit;
            safe_deadline = jobs[i].deadline;
        }
    }
    return max_profit;
}

int main () {
    vector<pair<int,int>> jobs = {{4,20},{1,10},{1,100},{1,30},{2,90}};
    cout << "\nMaximum Profit Is : " << max_profit_jobs(jobs) << endl;

    return 0;
}