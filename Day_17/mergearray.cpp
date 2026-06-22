#include<iostream>
using namespace std;
int main(){
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int merged_array[n1+n2];
    for(int i=0; i<n1; i++){
        merged_array[i] = arr1[i];
    }
    for(int i=0; i<n2; i++){
        merged_array[n1+i] = arr2[i];
    }
    cout<<"Merged array is: ";
    for(int i=0; i<n1+n2; i++){
        cout<<merged_array[i]<<" ";
    }
    return 0;   
}