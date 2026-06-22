#include<iostream>
using namespace std;
int main(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 4, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int union_array[n1+n2];
    int k = 0;
    for(int i = 0; i<n1; i++){
        union_array[k++] = arr1[i];
    }
    for(int i =0; i<n2; i++){
        bool found = false;
        for(int j = 0; j<n1; j++){
            if(arr2[i] == arr1[j]){
                found = true;
                break;
            }
        }
        if(!found){
            union_array[k++] = arr2[i];

        }

    }
    cout<<"union of two arrays is: ";
    for(int i =0; i<k; i++){
        cout<<union_array[i]<<" ";
    }
    return 0;
}