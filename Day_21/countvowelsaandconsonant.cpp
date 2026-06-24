#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int vowels = 0;
    int consonants = 0;
    int count = 0;
    cout<<"Enter a string: ";
    getline(cin, str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            vowels++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            consonants++;
        }
    
    }
    cout<<"Number of vowels: "<<vowels<<endl;
    cout<<"Number of consonants: "<<consonants<<endl;
    return 0;
}