#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    string result = "";
    cout<<"Enter a string: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        if(str[i] != ' '){
            result += str[i];
        }
    }
    cout<<"String after removing spaces is: "<<result<<endl;
    return 0;
}