#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    int n = str.length();
    string compressed = "";
    for(int i =0; i<n; i++){
        int count = 1;
        while(i<n-1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        compressed += str[i];
        compressed += to_string(count);
    }
    cout<<"Compressed string is: "<<compressed<<endl;
    return 0;

}