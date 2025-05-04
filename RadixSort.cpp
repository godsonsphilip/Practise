#include<bits/stdc++.h>
using namespace std;

void CountSort(vector<int>& a, int n, int exp){
    vector<int> cf(10, 0);

    //Chucking out the digits based on the current base::
    for(int i = 0; i<n; i++){
        cf[(a[i]/exp)%10]++;
    }

    auto t = a;
    //Cummulative Frequency:
    for(int i = 1; i<10; i++){
        cf[i] = cf[i] + cf[i-1];
    }

    for(int i = n-1; i>=0; i--){
        cf[(t[i]/exp)%10]--;
        a[cf[(t[i]/exp)%10]] = t[i];
    }
}

void RadixSort(vector<int>& a, int n){
    int max = *max_element(a.begin(), a.end());

    //Going to iterate till the maximum number of digits in the maximum number:
    for(int i = 1; max/i > 0; i*= 10){
        CountSort(a, n, i);
    }
}

void Display(vector<int>& a, int n){
    for(auto& i: a){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements: ";
    vector<int> a(n);
    for(auto& i: a){
        cin>>i;
    }

    RadixSort(a, n);
    Display(a,n);

    return 0;
}