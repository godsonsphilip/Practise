#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertion(vector<double>& a){
    for(int i = 1; i<a.size(); i++){
     double key = a[i];
        int j = i-1;
        while(j>=0 and a[j]> key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void BucketSort(vector<double>& a, int n){
    int size = n; //Number of Buckets
    vector<vector<double>> b(size);
    double maxi = *max_element(a.begin(), a.end());
    double mini = *min_element(a.begin(), a.end());
    double range = (maxi-mini)/size;
    for(int i = 0; i<n; i++){
        // int index = a[i]*n;   
        
        //If the element is above 1, then use the below formula for index:
        int index = (a[i]-mini)/range;
        if(index == size) index--;
        //where range = (max(a)-min(a))/size; 
        //aka Normalizing the  elements within the prescribed range

        b[index].push_back(a[i]);
    }   

    //Sorting individua Buckets:
    for(int i = 0; i<size; i++){
        insertion(b[i]);
    }

   a.clear();
    for(int i = 0; i<size; i++){
        for(int j =0; j<b[i].size(); j++){
            a.push_back(b[i][j]);
        }
    }
}

void Display(vector<double>& a, int n){
    for(auto& i: a){
        cout<<i<<" ";
    }cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;


    //Here the elements are in the range [0,1) 
    cout<<"Enter the elements: ";
    vector<double> a(n);
    for(auto& i: a){
        cin>>i;
    }

    BucketSort(a, n);
    Display(a, n);
    return 0;
}
