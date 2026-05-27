#include<iostream>
using namespace std;
int main(){
    int n;
    int count = 0;
    cout<<"Enter a number: ";
    cin>>n;
    while(n > 0){
        n = n/10;
        count++;
    }
    cout<<"Digits in a given number is: "<<count<<endl;
    return 0;

}
