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
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int evenCount = 0;
    int oddCount = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] % 2 == 0){
            evenCount++;
        }
        else{
            oddCount++;
        }
    }
    cout<<"Number of even elements: "<<evenCount<<endl;
    cout<<"Number of odd elements: "<<oddCount<<endl;   
    return 0;
 }

