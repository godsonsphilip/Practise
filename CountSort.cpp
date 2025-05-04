#include <bits/stdc++.h>
using namespace std;

void CountSort(vector<int>& a, int n){
    auto max = *max_element(a.begin(), a.end());
    vector<int> cf(max+1, 0);

    //Finding the frequency array for the elements present in vector a:
    for(auto& i: a){
        cf[i]++;
    }

    //Cummulative Frequency Array:
    //Prefix Sum:
    for(int i = 1; i<max+1; i++){
        cf[i] = cf[i] + cf[i-1];
    }

   auto t = a;

    //Starting from the back so as to maintain the stability of the sort:
    for(int i = n-1; i>=0; i--){
         cf[t[i]]--;
         a[cf[t[i]]] = t[i];
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
    for(auto &i: a){
        cin>>i;
    }
   CountSort(a,n);
    cout<<"Sorted array is: ";
    Display(a,n);

    return 0;
}
