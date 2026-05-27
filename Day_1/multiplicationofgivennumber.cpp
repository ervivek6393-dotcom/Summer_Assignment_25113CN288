#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i = 1; i <= 10; i++){
        int multiplication = n*i;
        cout<<n<<" * "<<i<<" = ";
        cout<<multiplication<<endl;

    }
}
