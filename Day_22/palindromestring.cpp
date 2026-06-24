#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    int start = 0;
    int end = str.length() - 1;
    while(start < end){
        if(str[start] != str[end]){
            cout<<"String is not palindrome"<<endl;
            return 0;
        }
        start++;
        end--;
    }
    cout<<"String is palindrome"<<endl;
    return 0;
}