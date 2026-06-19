#include<iostream>
using namespace std;
void max(int a , int b){
    if(a>b){
        cout<<a;

    }
    else{
        cout<<b;
    }
}
int main(){
    int a;
    cout<<"Enter num1: ";
    cin>>a;
    int b; 
    cout<<"Enter num2: ";
    cin>>b;
    max(a, b);
    return 0;
}