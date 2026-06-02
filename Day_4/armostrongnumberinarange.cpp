#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n1;
    cout<<"Enter a start number: ";
    cin>>n1;
    int n2;
    cout<<"Enter a end number: ";
    cin>>n2;
    
    for(int i =n1; i<=n2; i++){
        int temp = i;
        int count = 0;
        while(temp > 0){
            count++;
            temp = temp / 10;
        }
        int sum = 0;
        temp = i;

        while(temp > 0){
            int rem = temp % 10;
            sum = sum + pow(rem, count);
            temp = temp / 10;
        }
        if(sum == i){           
            cout<<i<<"  "<<endl;
            
        
    }
   
}
return 0;

}