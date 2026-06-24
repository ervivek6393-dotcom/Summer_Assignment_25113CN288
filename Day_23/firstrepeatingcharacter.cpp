#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        int count = 0;
        for(int j =0; str[j]!='\0'; j++){
            if(str[i] == str[j]){
                count++;
            }
        }
        if(count>1){
            cout<<"First repeating character is: "<<str[i]<<endl;
            return 0;
        }
    }

}