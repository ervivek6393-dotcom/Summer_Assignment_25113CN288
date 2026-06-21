#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i =0; i<n; i++){
        sum += arr[i];

    }
    int total = (n+1)*(n+2)/2;
    int missing_number = total - sum;
    cout<<"Missing number in array is: "<<missing_number<<endl;
    return 0; 
    }
