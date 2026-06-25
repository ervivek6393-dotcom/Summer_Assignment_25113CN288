#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of names: ";
    cin>>n;
    cin.ignore(); // To ignore the newline character after reading n
    string names[n];
    cout<<"Enter the names: "<<endl;
    for(int i =0; i<n; i++){
        getline(cin, names[i]);
        for(int j =0; j<i; j++){
            if(names[i] < names[j]){
                swap(names[i], names[j]);
            }
        }


    }
    // Display the sorted names
    cout<<"Names in alphabetical order: "<<endl;
    for(int i =0; i<n; i++){
        cout<<names[i]<<endl;
    }   
}