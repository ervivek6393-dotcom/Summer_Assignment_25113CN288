#include<iostream>
#include<string>
using namespace std;
int  main(){
    string str;
    int count = 0;
    cout<<"Enter a string: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        if(str[i] != ' ')
        count++;
    }
    cout<<"Length of string is: "<<count<<endl;
    return 0;
}