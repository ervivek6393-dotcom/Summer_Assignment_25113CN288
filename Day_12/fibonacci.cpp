#include<iostream>
using namespace std;
void fibonacci(int n){
    int a = 0;
    int b = 1;
    for(int i = 0; i<n; i++){
        cout<<a<<" ";
        int temp = a + b;
        a = b;
        b = temp;

    }
}
int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    fibonacci(n);
    return 0;
}