#include<bits/stdc++.h>
using namespace std;

// Combine Function
void merge(int arr[],int si,int mid,int ei){  
    vector<int> temp;
    int i = si;    // traverse on left half
    int j = mid+1;  // traverse on right half

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    // If one array ends then put remaining sorted nums of other array as it is.
    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    //Copy temp to main array.
    for(int i=si,x=0;i<=ei;i++){
        arr[i] = temp[x++];
    }
}

void mergesort(int arr[],int si,int ei){
    if(si>=ei){     // Base Case
        return;
    }
    int mid = si + (ei-si)/2; // Recursive division

    mergesort(arr,si,mid); // left half recursive call
    mergesort(arr,mid+1,ei); // Right half recursive call

    merge(arr,si,mid,ei);  // Combine function call

}


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;

    mergesort(arr,0,n-1);
    print(arr,n);
    return 0;
}