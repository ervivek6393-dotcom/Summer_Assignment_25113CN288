#include<iostream>
using namespace std;
void palindrome(int n){
    int original = n; 
    int rev = 0;
    while(n != 0){
        int ld = n%10;
        rev = rev*10 + ld;
        n = n/10;
    }
    if(original == rev){
        cout<<original<<" "<<"Palindrome"<<endl;
    }
    else{
        cout<<original<<" "<<"Not Palindrome"<<endl;
    }
   
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    palindrome(n);
    return 0;
}