#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of arraya: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of arrays: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int freq;
    cout<<"Enter the number to find frequency: ";
    cin>>freq;
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == freq){
            count++;
        }
    }
    cout<<"Frequency of "<<freq<<" is: "<<count;
    return 0;
}