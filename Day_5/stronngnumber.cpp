#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
   int  temp = n;
   int sum =0;
   while(temp>0){
    int rem = temp%10;
    int fact =1;
    for(int i=1; i<=rem; i++){
        fact = fact*i;
    }
    sum = sum + fact;
    temp = temp/10;

   }
   if(sum == n){
    cout<<n<<" is a strong number.";
   }
   else{
    cout<<n<<" is not a strong number.";        
   }
}
