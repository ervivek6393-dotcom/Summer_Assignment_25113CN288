#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of arrays:";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Reverse array is: ";
    for(int i = n-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}