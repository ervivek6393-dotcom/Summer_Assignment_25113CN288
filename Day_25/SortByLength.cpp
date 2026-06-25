#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a sentence: ";
    getline(cin, str);
    int n = str.length();
    string words[n];
    int wordCount = 0;
    for(int i =0; i<n; i++){
        if(str[i] == ' ' || i == n-1){
            if(i == n-1){
                words[wordCount] += str[i];
            }
            wordCount++;
        }
        else{
            words[wordCount] += str[i];
        }
    }
    cout<<"Words sorted by length: "<<endl;
    for(int i =0; i<wordCount; i++){
        for(int j =0; j<i; j++){
            if(words[i].length() < words[j].length()){
                swap(words[i], words[j]);
            }
        }
    }
    for(int i =0; i<wordCount; i++){
        cout<<words[i]<<endl;
    }  
  
}
