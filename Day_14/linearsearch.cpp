#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of arrays:";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int target ;
    cout<<"Enter the number to be searched: ";
    cin>>target;
    for(int i =0; i<n; i++ ){
        if(target == arr[i]){
        cout<<"Found at index "<<i;
        return 0;
    }
    }
    cout<<"Not Found";
    return 0;
}