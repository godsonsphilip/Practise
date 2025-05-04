#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void Merge(vector<int>& a, int l, int m , int r){
    int low = l;
    int high = m+1;
    vector<int> b;
    while(low<=m and high<=r){
        if(a[low]<=a[high]){
            b.push_back(a[low]);
            low++;
        }
        else {b.push_back(a[high]); high++;}
    }

    while(low<=m){
        b.push_back(a[low]);
        low++;
    }

    while(high<=r){
        b.push_back(a[high]);
        high++;
    }

    for(int i = l; i<=r; i++){
        a[i] = b[i-l]; //Here we have used i-l because the size of b is not equal to the size of a;
                    //So to balance things out and to correctly address the index of b we use i-l;
    }
}

void MSort(vector<int>& a, int l, int r){
    if(l==r) return;
    int mid = l + (r-l)/2;
    MSort(a,l,mid);
    MSort(a,mid+1,r);
    Merge(a, l, mid, r);
}

void MergeSort(vector<int>& a, int n){
   int l =0, r = n-1;
   MSort(a, l, r);
}

void Display(vector<int> a, int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
   
    cout<<"Enter number of elements: ";
     int n;
    cin >> n;
    cout<<"Enter the elements: ";
    vector<int> a(n);
    for(auto& i : a){
        cin>>i;
    }

    MergeSort(a, n);
    Display(a, n);

    return 0;
}

