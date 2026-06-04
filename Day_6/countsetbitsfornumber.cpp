#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int count =0;
    while(n>0){
        int rem = n%2;
        if(rem == 1){
            count++;
        }
        n = n/2;
    }
    cout<<count;
    return 0;
}
