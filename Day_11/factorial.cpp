#include<iostream>
using namespace std;
void fact(int n){
    int factorial = 1;
    for(int i=1; i<=n; i++){
        factorial *= i;
    }
    cout<<factorial<<endl;
}
int main(){
    int n;
    cout<<"Enter a number:" ;
    cin>>n;
    fact(n);
    return 0;
}