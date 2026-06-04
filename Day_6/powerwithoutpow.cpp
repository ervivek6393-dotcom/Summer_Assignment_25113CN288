#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter base: ";
    cin>>x;
    int n;
    cout<<"Enter power: ";
    cin>>n;
    int result =1;
    for(int i=1; i<=n; i++){
        result = result*x;
    }
    cout<<result;
    return 0;
}