#include<iostream>
using namespace std;
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int descending_array[n];
    for(int i = 0; i<n; i++){
        descending_array[i] = arr[n-i-1];
        cout<<descending_array[i]<<" ";
    }
    return 0;
}