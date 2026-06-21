#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j =0; 
    for(int i = 0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];
    cout<<"Array after removing duplicates is: ";
    for(int i =0; i<j; i++){
        cout<<arr[i]<<" ";
    }
}
