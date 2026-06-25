#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a sentence: ";
    getline(cin, str);
    string longest = "";
    string word = "";
    for(int i =0; i<=str.length(); i++){
        if(str[i] == ' ' || str[i] == '\0'){
            if(word.length() > longest.length()){
                longest = word;
            }
           
                word = "";
            }
            else{
                word += str[i];
            }

    }
    cout<<"Longest word is: "<<longest<<endl;
    return 0;
}