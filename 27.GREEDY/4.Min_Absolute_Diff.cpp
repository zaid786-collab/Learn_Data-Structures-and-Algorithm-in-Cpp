#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int> A{8,9,11,1,3};
    vector<int> B{3,7,5,9,2};

    int ans = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0;i<5;i++) {
        ans += abs(A[i] - B[i]);
    }

    cout << "Minimum Absolute Difference is : " << ans <<endl;

    return 0;

}