#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
int main(){
    string str;
    string str2;
    int choice;
    do{
        cout<<"==== MENU DRIVEN STRING OPERATIONS SYSTEM ===="<<endl;
        cout<<"1. Enter String"<<endl;
        cout<<"2. Display String"<<endl;
        cout<<"3. Find Length of String"<<endl;
        cout<<"4. Copy String"<<endl;
        cout<<"5. Concatenate Two Strings"<<endl;
        cout<<"6. Compare Two Strings"<<endl;
        cout<<"7. Search Substring"<<endl;
        cout<<"8. Convert to Uppercase"<<endl;
        cout<<"9. Convert to Lowercase"<<endl;
        cout<<"10. Reverse String"<<endl;
        cout<<"11. Count Vowels and Consonants"<<endl;
        cout<<"12. Count Words in String"<<endl;
        cout<<"13. Check Palindrome"<<endl;
        cout<<"14. Replace Substring"<<endl;
        cout<<"15. Remove Spaces"<<endl;
        cout<<"16. Check Anagram"<<endl;
        cout<<"17. Clear String"<<endl;
        cout<<"18. Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        cin.ignore(); // To ignore the newline character after choice input
        switch(choice){
            case 1: {
                cout<<"==== ENTER STRING ===="<<endl;
                cout<<"Enter a string: ";
                getline(cin, str);
                break;
            }
            case 2: {
                cout<<"==== DISPLAY STRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty!"<<endl;
                }
                else{
                    cout<<"String: "<<str<<endl;
                }
                break;
            }
            case 3: {
                cout<<"==== FIND LENGTH OF STRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty!"<<endl;
                }
                else{
                    cout<<"Length of String: "<<str.length()<<endl;
                }
                break;
            }
            case 4: {
                cout<<"==== COPY STRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot copy."<<endl;
                }
                else{
                    str2 = str;
                    cout<<"String copied to str2: "<<str2<<endl;
                }
                break;
            }
            case 5: {
                cout<<"==== CONCATENATE TWO STRINGS ===="<<endl;
                if(str.empty()){
                    cout<<"First string is empty! Cannot concatenate."<<endl;
                }
                else{
                    cout<<"Enter second string to concatenate: ";
                    getline(cin, str2);
                    str = str + " " + str2;
                    cout<<"Concatenated String: "<<str<<endl;
                }
                break;
            }
            case 6: {
                cout<<"==== COMPARE TWO STRINGS ===="<<endl;
                if(str.empty()){
                    cout<<"First string is empty! Cannot compare."<<endl;
                }
                else{
                    cout<<"Enter second string to compare: ";
                    getline(cin, str2);
                    if(str == str2){
                        cout<<"Strings are equal."<<endl;
                    }
                    else{
                        cout<<"Strings are not equal."<<endl;
                    }
                }
                break;
            }
            case 7: {
                cout<<"==== SEARCH SUBSTRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot search substring."<<endl;
                }
                else{
                    cout<<"Enter substring to search: ";
                    getline(cin, str2);
                    size_t found = str.find(str2);
                    if(found != string::npos){
                        cout<<"Substring found at position: "<<found + 1<<endl;
                    }
                    else{
                        cout<<"Substring not found!"<<endl;
                    }
                }
                break;
            }
            case 8: {
                cout<<"==== CONVERT TO UPPERCASE ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot convert."<<endl;
                }
                else{
                   for(int i = 0; i < str.length(); i++){
                        str[i] = toupper(str[i]);
                    }
                    cout<<"Uppercase String: "<<str<<endl;
                }
                break;
            }
            case 9: {
                cout<<"==== CONVERT TO LOWERCASE ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot convert."<<endl;
                }
                else{
                    for(int i = 0; i < str.length(); i++){
                        str[i] = tolower(str[i]);
                    }
                    cout<<"Lowercase String: "<<str<<endl;
                }
                break;
            }
            case 10: {
                cout<<"==== REVERSE STRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot reverse."<<endl;
                }
                else{
                    string reversedStr = str;
                    reverse(reversedStr.begin(), reversedStr.end());
                    cout<<"Reversed String: "<<reversedStr<<endl;
                }
                break;
            }
            case 11: {
                cout<<"==== COUNT VOWELS AND CONSONANTS ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot count."<<endl;
                }
                else{
                    int vowels = 0, consonants = 0;
                    for(int i = 0; i < str.length(); i++){
                        char c = str[i];
                        if(isalpha(c)){
                            char lowerC = tolower(c);
                            if(lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u'){
                                vowels++;
                            }
                            else{
                                consonants++;
                            }
                        }
                    }
                    cout<<"Vowels: "<<vowels<<", Consonants: "<<consonants<<endl;
                }
                break;
            }
            case 12: {
                cout<<"==== COUNT WORDS IN STRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot count words."<<endl;
                }
                else{
                    int wordCount = 0;
                    bool inWord = false;
                    for(int i = 0; i < str.length(); i++){
                        char c = str[i];
                        if(isspace(c)){
                            inWord = false;
                        }
                        else if(!inWord){
                            inWord = true;
                            wordCount++;
                        }
                    }
                    cout<<"Number of Words: "<<wordCount<<endl;
                }
                break;
            }
            case 13: {
                cout<<"==== CHECK PALINDROME ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot check palindrome."<<endl;
                }
                else{
                   string temp = str;
                   for(int i = 0; i < temp.length(); i++){
                        temp[i] = tolower(temp[i]);
                    }
                    string reversedStr = temp;
                    reverse(reversedStr.begin(), reversedStr.end());
                    if(temp == reversedStr){
                        cout<<"String is a palindrome."<<endl;
                    }
                    else{
                        cout<<"String is not a palindrome."<<endl;
                    }
                }
                break;
            }
            case 14: {
                cout<<"==== REPLACE SUBSTRING ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot replace substring."<<endl;
                }
                else{
                    cout<<"Enter substring to replace: ";
                    getline(cin, str2);
                    cout<<"Enter new substring: ";
                    string newSubstr;
                    getline(cin, newSubstr);
                    size_t pos = str.find(str2);
                    if(pos != string::npos){
                        str.replace(pos, str2.length(), newSubstr);
                        cout<<"Updated String: "<<str<<endl;
                    }
                    else{
                        cout<<"Substring not found!"<<endl;
                    }
                }
                break;
            }
            case 15: {
                cout<<"==== REMOVE SPACES ===="<<endl;
                if(str.empty()){
                    cout<<"String is empty! Cannot remove spaces."<<endl;
                }
                else{
                   string temp = str;
                    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
                    cout<<"String without spaces: "<<temp<<endl;
                }
                break;
            }
            case 16: {
                cout<<"==== CHECK ANAGRAM ===="<<endl;
                if(str.empty()){
                    cout<<"First string is empty! Cannot check anagram."<<endl;
                }
                else{
                   cout<<"Enter second string to check anagram: ";
                   getline(cin, str2);
                   string first = str;
                   string second = str2;
                   for(int i =0; i < first.length(); i++){
                        first[i] = tolower(first[i]);
                    }
                    for(int i =0; i < second.length(); i++){
                        second[i] = tolower(second[i]);
                    }
                    sort(first.begin(), first.end());
                    sort(second.begin(), second.end());
                    if(first == second){
                        cout<<"Strings are anagrams."<<endl;
                    }
                    else{
                        cout<<"Strings are not anagrams."<<endl;
                    }
                }
                break;
            }
            case 17: {
                cout<<"==== CLEAR STRING ===="<<endl;
                str.clear();
                cout<<"String cleared!"<<endl;
                break;
            }
            case 18: {
                cout<<"Exiting the program. Goodbye!"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice! Please try again."<<endl;
                break;
            }

          
        }

     

    }while(choice != 18);
    return 0;
}