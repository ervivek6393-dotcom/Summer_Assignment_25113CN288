#include<iostream>
using namespace std;
int main(){
    int n;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    double average = (double)sum/n;
    cout<<"Sum of the array is: "<<sum<<endl;
    cout<<"Average of the array is: "<<average<<endl;
    return 0;
}