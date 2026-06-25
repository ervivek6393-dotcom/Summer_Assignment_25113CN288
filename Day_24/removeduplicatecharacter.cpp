#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"String after removing duplicate characters: ";
    for(int i =0; i<str.length(); i++){
        int j;
        for(j=0; j<i; j++){
            if(str[i] == str[j]){
                break;
            }
        }
        if(i == j){
            cout<<str[i];
        }
    }
    cout<<endl;

}