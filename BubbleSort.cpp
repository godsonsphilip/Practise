#include <iostream>
using namespace std;
void BubbleSort(int a[], int n);
void Display(int a[], int n);

void BubbleSort(int a[], int n){
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=n-1-i; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
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

    BubbleSort(a, n);
    Display(a, n);

    return 0;
}

