#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 0, 2, 0, 3, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] != 0){
            arr[count++] = arr[i];
        }
    }
    while(count<n){
        arr[count++] = 0;

    }
    cout<<"Array after moving zeros to end is: ";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}