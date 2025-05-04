#include<bits/stdc++.h>
using namespace std;

int Part(vector<int>& a, int low, int high){
    int i = low, j = high;
    int pivot = a[low];
    while(i<=j){
        while(i<=high and a[i]<=pivot) i++;
        while(j>=low and a[j]>pivot) j--;
        swap(a[i], a[j]);
    }
    swap(a[j], a[low]);
    return j;
}

void QuickSort(vector<int>& a, int low, int high){
    if(low<high) {
    int pivot = Part(a, low, high);
    QuickSort(a, low, pivot-1);
    QuickSort(a, pivot+1, high);}
}

void Display(vector<int>& a, int n){
    for(auto& i: a) cout<<i<<" ";
    cout<<endl;
}

int main(){
    cout<<"Enter the number of Elements: ";
    int n; cin>>n;
    cout<<"Enter the elements: ";
    vector<int> a(n);
    for(auto& i: a){
        cin>>i;
    }

    QuickSort(a,0,n-1);
    Display(a,n);
}