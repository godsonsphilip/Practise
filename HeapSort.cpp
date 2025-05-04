#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int k){
    int largest = k, l = 2*k+1, r = 2*k+2;
    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n and a[r]>a[largest]) largest = r;
    if(largest!=k){
        swap(a[largest], a[k]);
        heapify(a, n, largest);
    }
}

void HeapSort(vector<int>& a, int n){
    for(int i = n/2 - 1; i>=0; i--){
        heapify(a, n, i);
    }

    for(int i =n-1; i>0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void display(vector<int> a, int n){
    for(auto& i: a){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    HeapSort(a, n);
    display(a, n);

    return 0;
}