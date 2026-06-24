#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int matrix[n][n];
    cout<<"Enter the elements of matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    bool issymmetric = true;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(matrix[i][j] != matrix[j][i]){
                issymmetric = false;
                break;

            }
        }
    }
    if(issymmetric){
        cout<<"Matrix is symmetric."<<endl;
    }
    else{
        cout<<"Matrix is not symmetric."<<endl;
    }
    return 0;
    }
