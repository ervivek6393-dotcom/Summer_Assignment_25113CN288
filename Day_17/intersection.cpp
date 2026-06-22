#include<iostream>
using namespace std;
int main(){
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int intersection_array[n1<n2?n1:n2];
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if(arr1[i] == arr2[j]){
                intersection_array[i] = arr1[i];
                cout<<"Intersection: "<<intersection_array[i]<<endl;
            }
        }
    }
    return 0;
    
}