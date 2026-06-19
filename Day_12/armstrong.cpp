    #include<iostream>
    #include<cmath>
    using namespace std;
    void armstrong(int n){
        int count = 0;
       int original = n;
        int temp = n;
        int sum = 0;
        while(temp != 0){
            count++;
            temp = temp/10;
    }
    temp = n;
        while(temp!= 0){
            int digit = temp%10;
            sum = sum + (round(pow(digit, count)));
            temp = temp/10;
        }
        if(sum == original){
            cout<<original<<" is an armstrong number."<<endl;
        }
        else{
            cout<<original<<" is not an armstrong number."<<endl;
        }
    }
    int main(){
        int n;
        cout<<"Enter a number: ";
        cin>>n;
        armstrong(n);
        return 0;
    }
