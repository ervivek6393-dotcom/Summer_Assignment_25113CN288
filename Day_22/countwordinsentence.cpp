#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int count  = 1;
    cout<<"Enter a string: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        if(str[i] == ' ')
           count++;
    }
    cout<<"Number of words in string is: "<<count<<endl;
    return 0;


}

