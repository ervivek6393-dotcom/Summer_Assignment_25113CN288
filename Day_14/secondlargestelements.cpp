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
        int max = arr[0];
        for(int i =1; i<n; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        int secondmax = arr[0];
        for(int i =1; i<n; i++){
            if(arr[i]>secondmax && arr[i]<max){
                secondmax = arr[i];
            }
        }
        cout<<"Second largest element is: "<<secondmax;
        return 0;
    }

        