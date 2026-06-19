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
    int max = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
            
        }
       
    }
     cout<<"Maximum Element:"<<max<<endl;
    int min = arr[0];
    for(int i =1; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
            
        }
   
    }
        cout<<"Minimum Element:"<<min<<endl;
    return 0;

    

}