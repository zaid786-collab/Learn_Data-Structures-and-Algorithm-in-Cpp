#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high) {
    vector<int> temp;
    int i = low;
    int j = mid+1;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= high) {
        temp.push_back(arr[j++]);
    }

    for(int i=low;i<=high;i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int>& arr,int low,int high) {
    if(low >= high) {
        return;
    }
    int mid = low + (high - low)/2;

    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

int main () {
    vector<int> arr = {19,23,12,89,76,12,34,90,45};
    int n = arr.size() - 1;

    mergesort(arr,0,n);

    for(int i=0;i<=n;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}





// #include<bits/stdc++.h>
// using namespace std;

// // Combine Function
// void merge(int arr[],int si,int mid,int ei){  
//     vector<int> temp;
//     int i = si;    // traverse on left half
//     int j = mid+1;  // traverse on right half

//     while(i<=mid && j<=ei){
//         if(arr[i]<=arr[j]){
//             temp.push_back(arr[i++]);
//         }
//         else{
//             temp.push_back(arr[j++]);
//         }
//     }
//     // If one array ends then put remaining sorted nums of other array as it is.
//     while(i<=mid){
//         temp.push_back(arr[i++]);
//     }

//     while(j<=ei){
//         temp.push_back(arr[j++]);
//     }

//     //Copy temp to main array.
//     for(int i=si,x=0;i<=ei;i++){
//         arr[i] = temp[x++];
//     }
// }

// void mergesort(int arr[],int si,int ei){
//     if(si>=ei){     // Base Case
//         return;
//     }
//     int mid = si + (ei-si)/2; // Recursive division

//     mergesort(arr,si,mid); // left half recursive call
//     mergesort(arr,mid+1,ei); // Right half recursive call

//     merge(arr,si,mid,ei);  // Combine function call

// }


// void print(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }


// int main(){
//     int arr[6] = {6,3,7,5,2,4};
//     int n = 6;

//     mergesort(arr,0,n-1);
//     print(arr,n);
//     return 0;
// }