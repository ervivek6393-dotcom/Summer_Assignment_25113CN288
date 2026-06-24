#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    
    cout<<"Enter a string: ";
    getline(cin, str);
    for(int i =0; str[i]!='\0'; i++){
        bool flag = false;
        for(int j =0; j<i; j++){
            if(str[i] == str[j]){
                flag = true;
                break;
            }

        } 
        if(flag == true){
            continue;
        }
        int count = 0;
        for(int j =0; str[j]!='\0'; j++){
            if(str[i] == str[j]){
                count++;
            }

        }
        cout<<str[i]<<" = "<<count<<endl;
       
    }
    return 0;

}