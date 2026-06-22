#include<iostream>
using namespace std;
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n-1;
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == key){
            cout<<"Element found at index: "<<mid<<endl;
            break;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}