#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void SelectionSort(int a[], int n);
void Display(int a[], int n);

void SelectionSort(vector<int>& a, int n){
    for(int i = 0; i<n-1; i++){
        // int m = i; 
        // for(int j = 1; j<n; j++){
        //     if(a[m]>a[j]){
        //         m = j;
        //     }
        // }
        int m = *min_element(a.begin()+i, a.end());
        for(int j = 0; j<n; j++){
            if(a[j]==m){
                swap(a[j], a[i]);
                break;
            }
           }
    }
}

void Display(vector<int>& a, int n){
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

    SelectionSort(a, n);
    Display(a, n);

    return 0;
}

