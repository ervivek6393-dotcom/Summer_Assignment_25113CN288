#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter the term to be find: ";
    cin>>n;
    int a = 0 , b = 1, c;
    for(int i=0; i<n-1; i++){
        c = a + b;
        a = b; 
        b = c;
    }
    cout<<a<<" ";
    
    return 0;
} 