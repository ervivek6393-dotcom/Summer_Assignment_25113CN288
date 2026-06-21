#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,  3, 2, 4, 5, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] + arr[j] == 9){
                cout<<"Pair:" <<arr[i]<<"," <<arr[j]<<endl;
            }
        }

    }
    return 0;
}