#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1, str2;
    cout<<"Enter first string: ";
    getline(cin, str1);
    cout<<"Enter second string: ";
    getline(cin, str2);
    if(str1.length() != str2.length()){
        cout<<"String are not rotations of each other."<<endl;
        return 0;
    }
    string temp = str1 + str1;
    if(temp.find(str2) != string::npos){
        cout<<"String are rotations of each other."<<endl;
    }
    else{
        cout<<"String are not rotations of each other."<<endl;
    }
    return 0;
    

}
