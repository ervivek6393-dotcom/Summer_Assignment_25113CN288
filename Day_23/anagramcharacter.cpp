#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1, str2;
    cout<<"Enter the  first string: ";
    getline(cin, str1);
    cout<<"Enter the second string: ";
    getline(cin, str2);
    if(str1.length() != str2.length()){
        cout<<"Strings are not anagrams"<<endl;
        return 0;

    }
    int freq1[26] = {0};
    int freq2[26] = {0};
    for(int i =0; str1[i]!='\0'; i++){
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++;
    }
    for(int i =0; i<26; i++){
        if(freq1[i] != freq2[i]){
            cout<<"Strings are not anagrams"<<endl;
            return 0;
        }
    }
    cout<<"Strings are anagrams"<<endl; 
    return 0;

}