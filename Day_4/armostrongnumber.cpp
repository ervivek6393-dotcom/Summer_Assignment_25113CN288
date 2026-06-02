#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum = 0, temp = n;
    int count = 0; 
    int temp1 = n;
    
    while(temp1 > 0){
        count++;
        temp1 = temp1 / 10;
    }
    
    while(temp > 0){
        int rem = temp % 10;
        sum = sum + pow(rem, count);
        temp = temp / 10;
    }
    if(sum == n){
        cout<<n<<" is an Armstrong number."<<endl;
    }
    else{
        cout<<n<<" is not an Armstrong number."<<endl;
    }
    return 0;
}