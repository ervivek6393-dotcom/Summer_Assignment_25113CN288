#include<iostream>
using namespace std;
int main(){
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}