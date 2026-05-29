#include<iostream>
using namespace std;
int main(){
    int n;
    int prd = 1;
    cout<<"Enter a number: ";
    cin>>n;
    while(n != 0){
        int ld = n % 10;
        prd = prd*ld;
        n = n/10;
    }
    cout<<prd;
}