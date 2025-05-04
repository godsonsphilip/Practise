#include <iostream>
using namespace std;
void InsertionSort(int a[], int n);
void Display(int a[], int n);

void InsertionSort(int a[], int n){
    for(int i = 1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 and a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void Display(int a[], int n){
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
    int a[n];
    for(auto& i : a){
        cin>>i;
    }

    InsertionSort(a, n);
    Display(a, n);

    return 0;
}

