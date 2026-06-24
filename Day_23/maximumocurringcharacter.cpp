#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int count = 0; 
    cout<<"Enter a string: ";
    int freq[26] = {0};
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        freq[str[i] - 'a']++;

    }
    int max = 0;
    char result;
    for(int i =0; i<26; i++){
        if(freq[i] > max){
            max = freq[i];
            result = i + 'a';
        }
    }
    cout<<"Maximum occurring character is: "<<result<<endl;
    return 0;
}