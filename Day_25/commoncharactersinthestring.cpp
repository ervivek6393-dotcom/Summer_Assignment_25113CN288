#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1, str2;
    cout<<"Enter the first string: ";
    getline(cin, str1);
    cout<<"Enter the second string: ";
    getline(cin, str2);
    string commonChars = "";
    for(int i =0; i<str1.length(); i++){
        for(int j =0; j<str2.length(); j++){
            if(str1[i] == str2[j]){
                if(commonChars.find(str1[i]) == string::npos){
                    commonChars += str1[i];
                }
            }
        }
    }
    cout<<"Common characters in both strings: "<<commonChars<<endl;
    return 0;
}
