#include<iostream>
using namespace std;
int main (){
    int n1;
    cout<<"Enter n1: ";
    cin>>n1;
    int n2;
    cout<<"Enter n2: ";
    cin>>n2;
    int max;
    for(int i = 1; i <= n1 && i <= n2; i++){
        if(n1 % i == 0 && n2 % i == 0){
            cout<<i<<" ";
            max = i;
        }
        cout<<"LCM: "<<(n1*n2)/max;
        return 0;
    
    }
    
}