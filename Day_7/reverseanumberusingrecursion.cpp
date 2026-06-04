#include<iostream>
using namespace std;
int rev =0;
int reverse(int n){
    if(n==0) return rev;
    int rem = n%10;
    rev = rev*10 + rem;
    return reverse(n/10);
    
 }
 int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<reverse(n);
    return 0;
 }
