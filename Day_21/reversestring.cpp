#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int reverse = 0;
    cout<<"Enter a string: ";
    getline(cin, str);
    cout<<"Reverse of atring is: ";
    for(int i = str.length()-1; i>= 0; i--){
        cout<<str[i];

    }

    return 0;
}