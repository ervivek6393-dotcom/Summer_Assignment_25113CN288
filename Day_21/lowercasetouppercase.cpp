#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string in lower case: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    cout<<"string in upper case is: " <<str<<endl;
    return 0;
    
}