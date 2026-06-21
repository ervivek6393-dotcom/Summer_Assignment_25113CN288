#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int max_freq = 0;
    int max_freq_element = arr[0];
    for(int i =0; i<n; i++){
        int count = 0;
        for(int j =0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max_freq){
            max_freq = count;
            max_freq_element = arr[i];
        }
    }
    cout<<"Element with maximum frequency is: "<<max_freq_element<<" with frequency: "<<max_freq<<endl;
    return 0;
       
    }
    
 